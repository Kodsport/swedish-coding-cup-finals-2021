// Usage: ./validator .in-file .ans-file dir <in >out
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <signal.h>
using namespace std;

const char* out_dir = nullptr;

void judge_message(const string& msg) {
	cerr << msg << endl;
	if (out_dir) {
		string fname = out_dir + string("/judgemessage.txt");
		ofstream fout(fname.c_str());
		fout << msg << endl;
	}
}

[[noreturn]]
void reject(const string& msg) {
	judge_message(msg);
	exit(43);
}

[[noreturn]]
void reject_line(const string& msg, const string& line) {
	judge_message(msg + ", with input " + line);
	exit(43);
}

[[noreturn]]
void accept(const string& msg) {
	judge_message(msg);
	exit(42);
}

[[noreturn]]
void judge_error2(const char* a, const char* b, const char* c) {
	string msg = string(a) + b + c;
	cerr << msg << endl;
	if (out_dir) {
		string fname = out_dir + string("/judgeerror.txt");
		ofstream fout(fname.c_str());
		fout << msg << endl;
	}
	abort();
}

#undef assert
#define STR2(x) #x
#define STR(x) STR2(x)
#define assert(x) do { if (!(x)) { judge_error2(__FILE__ ":" STR(__LINE__) ": ", __PRETTY_FUNCTION__, ": Assertion `" #x "' failed."); } } while (0)


const int maxQueries = 200;

int main(int argc, char** argv) {
	assert(argc >= 2);
	if (argc >= 4) out_dir = argv[3];
	ifstream fin(argv[1]);
	int n;
	fin >> n;
	vector<int> vals(n);
	for (int i = 0; i < n; i++){
		fin >> vals[i];
	}
	vector<int> sums(n+1);
	for (int i = 0; i < n; i++){
		sums[i+1] = sums[i] + vals[i];
	}
	int sum = sums[n];
	string dummy;
	assert(!(fin >> dummy));

	cout << n << endl;

	int num = 0;
	while (num <= maxQueries) {
		char qtype;
		cin >> qtype;
		if (!cin) reject("eof");

		if (qtype == '?'){
			long long a, b, c, d;
			cin >> a >> b >> c >> d;
			if (!cin) reject("bad ? query");
			if (!(0 <= a && a <= b && b <= c && c <= d && d <= n)){
				reject("out of range for ? query");
			}
			int cnt1 = sums[b] - sums[a];
			int cnt2 = sums[d] - sums[c];
			if (cnt2 > cnt1) {
				cout << 1 << endl;
			} else if (cnt2 < cnt1) {
				cout << -1 << endl;
			} else if (cnt2 == cnt1) {
				cout << 0 << endl;
			}
		} else if (qtype == '!') {
			long long ans;
			cin >> ans;
			if (!cin) reject("bad ! query");
			if (ans != sum) reject("wrong: " + to_string(ans) + " vs " + to_string(sum));
			if (cin >> dummy) reject("expected eof");
			accept("ac");
		} else {
			reject("invalid query");
		}
		num++;
		if (num == maxQueries+1){
			reject("too many queries");
		}
	}
}
