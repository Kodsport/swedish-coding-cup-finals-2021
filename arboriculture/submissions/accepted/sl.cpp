#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi pars[2];
vector<vi> chs[2];
const int inf = 300'000; // another inf than js

// kactl
pair<int, vi> hungarian(const vector<vi> &a) {
	if (a.empty()) return {0, {}};
	int n = sz(a) + 1, m = sz(a[0]) + 1;
	vi u(n), v(m), p(m), ans(n - 1);
	rep(i,1,n) {
		p[0] = i;
		int j0 = 0; // add "dummy" worker 0
		vi dist(m, INT_MAX), pre(m, -1);
		vector<bool> done(m + 1);
		do { // dijkstra
			done[j0] = true;
			int i0 = p[j0], j1, delta = INT_MAX;
			rep(j,1,m) if (!done[j]) {
				auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
				if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
				if (dist[j] < delta) delta = dist[j], j1 = j;
			}
			rep(j,0,m) {
				if (done[j]) u[p[j]] += delta, v[j] -= delta;
				else dist[j] -= delta;
			}
			j0 = j1;
		} while (p[j0]);
		while (j0) { // update alternating path
			int j1 = pre[j0];
			p[j0] = p[j1], j0 = j1;
		}
	}
	rep(j,1,m) if (p[j]) ans[p[j] - 1] = j - 1;
	return {-v[0], ans}; // min cost
}

int cost(int to, int from) {
	auto& tov = chs[0][to];
	auto& fromv = chs[1][from];
	if (sz(tov) > sz(fromv)) {
		return inf;
	}
	vector<vi> mat(sz(tov), vi(sz(fromv)));
	rep(i,0,sz(fromv)) rep(j,0,sz(tov)) {
		mat[j][i] = cost(tov[j], fromv[i]);
	}
	return hungarian(mat).first + (sz(fromv) - sz(tov));
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int numTrees[2];
	cin >> numTrees[0] >> numTrees[1];
	rep(it,0,2) {
		int numNodes = 1;
		vi par(1, -1);
		vector<vi> ch;
		rep(i,0,numTrees[it]) {
			int eds;
			cin >> eds;
			par.push_back(0);
			rep(j,0,eds) {
				int p;
				cin >> p;
				par.push_back(numNodes + p);
			}
			numNodes += eds + 1;
		}
		ch.resize(numNodes);
		rep(i,1,numNodes) {
			ch[par[i]].push_back(i);
		}
		pars[it] = move(par);
		chs[it] = move(ch);
	}
	cout << cost(0, 0) - numTrees[1] + numTrees[0] << endl;
	exit(0);
}
