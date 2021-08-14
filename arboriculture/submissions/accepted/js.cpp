#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vi> children(2);

int readTree() {
  int V;
  cin >> V;
  int root = sz(children);
  children.push_back(vi());
  rep(i,1,V+1) {
    int par;
    cin >> par;
    children[par + root].push_back(i + root);
    children.push_back(vi());
  }
  return root;
}

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

const int INF = 1'000'000; // >>> E, which is max answer

int solve(int start, int goal) {
  int schildren = sz(children[start]), gchildren = sz(children[goal]);
  if (schildren < gchildren) {
    return INF;
  }
  vector<vi> costs(gchildren, vi(schildren));
  rep(g,0,gchildren) rep(s,0,schildren) {
    costs[g][s] = solve(children[start][s], children[goal][g]);
  }
  // If we have more branches than needed, we must cut them away
  int extracost = schildren - gchildren;
  return hungarian(costs).first + extracost;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

  int goals, starts;
  cin >> goals >> starts;
  rep(i,0,goals) {
    int nroot = readTree();
    children[0].push_back(nroot);
  }
  rep(i,0,starts) {
    int nroot = readTree();
    children[1].push_back(nroot);
  }
  cout << solve(1, 0) - (starts - goals) << endl;
}
