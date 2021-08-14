#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<string> wl;
vector<vector<vi>> mem;

const char preA = (char)('a' - 1);

bool rec(int a, int b, int at) {
	if (b - a <= 1) return 1;
	int& out = mem[a][b][at];
	if (out != -1) return out;

	if (wl[a][at] == preA) a++;

	vi group = {a};
	rep(i,a+1,b) {
		if (wl[i][at] != wl[i-1][at]) {
			group.push_back(i);
		}
	}

	if (sz(group) == 1 && wl[a][at] == 'a') {
		// Split a/aa somewhere in the middle
		if (rec(a, b, at + 1)) return out = 1;

		for (int i = b-1; i >= a; i--) {
			if (wl[i][at + 1] != 'a') break;
			if (rec(a, i, at + 1) && rec(i, b, at + 2)) return out = 1;
		}
		return out = 0;
	}

	// Check that groups are ordered and recurse on each
	rep(i,0,sz(group)) {
		int lo = group[i], hi = (i == sz(group)-1 ? b : group[i+1]);
		char ch = wl[lo][at];
		if (ch == 'a' && i == sz(group)-1) { // aa
			rep(j,lo,hi) if (wl[j][at + 1] != 'a') return out = 0;
			if (!rec(lo, hi, at + 2)) return out = 0;
		} else {
			if (i > 0 && ch < wl[group[i-1]][at]) return out = 0;
			if (!rec(lo, hi, at + 1)) return out = 0;
		}
	}
	return out = 1;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	wl.resize(N);
	mem.assign(N, vector<vi>(N+1, vi(2002, -1)));
	rep(i,0,N) cin >> wl[i], wl[i] += preA;
	cout << (rec(0, N, 0) ? "yes" : "no") << endl;
	exit(0);
}
