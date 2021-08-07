#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int N, Q, K;
	cin >> N >> Q >> K;
	string str, s;
	cin >> str;
	vi inds(N-1);
	rep(i,0,N-1) {
		inds[i] = (str[i] - 'a') * 26 + (str[i+1] - 'a');
	}
	int active[26 * 26]{};
	rep(qi,0,Q) {
		cin >> s;
		rep(i,0,K) {
			int a = s[2*i] - 'a';
			int b = s[2*i+1] - 'a';
			active[26 * a + b] = 1;
		}
		int res = 0, picked = 0;
		rep(i,0,N-1) {
			picked = active[inds[i]] & ~picked;
			res += picked;
		}
		cout << res << '\n';
		rep(i,0,K) {
			int a = s[2*i] - 'a';
			int b = s[2*i+1] - 'a';
			active[26 * a + b] = 0;
		}
	}
	exit(0);
}
