#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define trav(a, x) for(auto& a : x)
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;

static string input_file, output_dir, answer_file;

void die(const string& msg) {
	cout << msg << endl;
	ofstream(output_dir + "/score.txt") << 0;
	exit(43);
}

void accept(long double score) {
	ofstream(output_dir + "/score.txt") << setprecision(2) << fixed << score;
	exit(42);
}

void judge_error(const string& msg) {
	cout << msg << endl;
	exit(1);
}

template <class F>
void assert_done(istream& is, F fail) {
	try {
		string dummy;
		is >> dummy;
		if (is) fail("extraneous data: " + dummy);
	} catch(...) {}
}

class bigint{
	// A simple bigint class with only + and <, with numbers represented in base 2
	vector<int> num;
public:
	explicit bigint(long long v) {
		while(v != 0){
			num.push_back(v%2);
			v /= 2;
		}
	}
	bigint operator+(const bigint &v) {
		bigint res(0);
		int carry = 0;
		for(size_t c1 = 0; c1 < max(num.size(), v.num.size()); c1++){
			int x = 0;
			if(c1 < num.size()){
				x = num[c1];
			}
			int y = 0;
			if(c1 < v.num.size()){
				y = v.num[c1];
			}
			carry += x + y;
			res.num.push_back(carry%2);
			carry /= 2;
		}
		res.num.push_back(carry);
		while(res.num.back() == 0){
			res.num.pop_back();
			if(res.num.size() == 0)break;
		}
		return res;
	}

	bool operator<(const bigint &v) {
		if(num.size() != v.num.size())return num.size() < v.num.size();
		if(num.size() == 0)return 0;
		for(int c1 = (int)num.size()-1; c1 >= 0; c1--){
			if(num[c1] < v.num[c1])return 1;
			if(num[c1] > v.num[c1])return 0;
		}
		return 0;
	}

	long long to_ll(){
		long long res = 0;
		long long p = 1;
		for(int c1 = 0; c1 < (int)num.size(); c1++){
			res += p * num[c1];
			p *= 2;
		}
		return res;
	}
};

int ANS = 0;
int FIND(int i, vector<int> &parent){
	while(parent[i] != i){
		i = parent[i];
		ANS += 1;
	}
	return i;
}
void UNION(int i, int j, vector<int> &parent, vector<bigint> &size){
	i = FIND(i, parent);
	j = FIND(j, parent);
	if(size[i] < size[j]){
		swap(i, j);
	}
	size[i] = size[i] + size[j];
	parent[j] = i;
}

template <class F>
long double score(int n, int m, F fail) {

	// Validate
	set<pair<int,int>> seen;
	vector<pair<int,int>> edges;
	for(int c1 = 0; c1 < m; c1++){
		int u, v;
		if(!(cin >> u))fail("Could not read answer.\n");
		if(!(cin >> v))fail("Could not read answer.\n");
		if(u < 1 || u > n || v < 1 || v > n)fail("Edge index out of range.\n");
		if(u == v)fail("Self loop.\n");
		u--;
		v--;
		edges.push_back({u, v});
		if(u > v)swap(u, v);
		if(seen.find({u, v}) != seen.end())fail("Duplicate edge.\n");
		seen.insert({u, v});
	}

	// Score
	vector<bigint> size;
	vector<int> parent;
	for(int c1 = 0; c1 < n; c1++){
		size.push_back(bigint(1));
		parent.push_back(c1);
	}
	for(int c1 = 0; c1 < m; c1++){
		int u = edges[c1].first;
		int v = edges[c1].second;
		UNION(u, v, parent, size);
	}

	return double(ANS);
}

int main(int argc, char** argv) {
	if (argc < 4) exit(1);
	cin.sync_with_stdio(0);
	cin.tie(0);

	input_file = argv[1];
	answer_file = argv[2];
	output_dir = argv[3];

	ifstream fin(input_file);
	fin.exceptions(cin.failbit | cin.badbit | cin.eofbit);

	int n, m;
	fin >> n >> m;
	assert_done(fin, die);
	fin.close();

	try {
		long double sc = score(n, m, die);
		if(n < 100)accept(0); // zero for the sample
		accept(sc);
	} catch(...) {
		die("IO failure");
	}
}
