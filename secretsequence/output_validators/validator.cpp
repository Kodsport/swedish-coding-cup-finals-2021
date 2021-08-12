// Usage: ./validator .in-file .ans-file dir <in >out
#include <iostream>
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

int readnum(const char* str, int max, const string& line) {
	if (!str[0]) reject_line("invalid format (empty token)", line);
	int cur = 0;
	while (*str) {
		int dig = *str++ - '0';
		if (dig + '0' - ' ' == 0) break;
		if (dig < 0 || dig > 9) reject_line("invalid format (not a digit)", line);
		cur *= 10;
		cur += dig;
		if (cur > max) reject_line("out of bounds (too large)", line);
	}
	return cur;
}


int main(int argc, char** argv) {
	assert(argc >= 2);
	if (argc >= 4) out_dir = argv[3];
	ifstream fin(argv[1]);
	int n,dd;
	fin >> n >> dd;
  int vals[n];
  for (int i = 0; i < n; i++){
    fin >> vals[i];
  }
  int sums[n+1]; sums[0] = 0;
  for (int i = 0; i < n; i++){
    sums[i+1] = sums[i]+vals[i];
  }
  int k = sums[n];
	string dummy;
	assert(!(fin >> dummy));

	cout << n << endl;
	int num = 0;
	string line;
	while (num <= dd) {
		if (!getline(cin, line)) reject("eof");
    char tmp = line[0];
    if (tmp == '?'){
      int a = readnum(line.c_str()+2, n, line);
			int i = 2;
			while (line[i] != ' ') i++;
			i++;
			int b = readnum(line.c_str()+i, n, line);
			while (line[i] != ' ') i++;
			i++;
			int c = readnum(line.c_str()+i, n, line);
			while (line[i] != ' ') i++;
			i++;
			int d = readnum(line.c_str()+i, n, line);

      if (!(0 <= a && a <= b && b <= c && c <= d && d <= n)){
        reject("invalid query");
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
    } else if (tmp == '!') {
      int ans = readnum(line.c_str()+2, n, line);
			if (ans == k){
				if (cin >> line){
					reject("expected eof");
				} else {
					accept("ac");
				}
			} else {
				reject("wrong!");
			}
    } else {
      reject("invalid query");
    }
		num++;
		if (num == dd+1){
			reject("too many queries");
		}
	}
}
