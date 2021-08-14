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

const int INF = 1'000'000; // >>> E, which is max answer

int solve(int start, int goal) {
  int schildren = sz(children[start]), gchildren = sz(children[goal]);
  if (schildren < gchildren) {
    return INF;
  }
  vector<vi> costs(gchildren + 1, vi(schildren));
  rep(g,0,gchildren) rep(s,0,schildren) {
    costs[g][s] = solve(children[start][s], children[goal][g]);
  }
  rep(s,0,schildren) {
    costs[gchildren][s] = 1;
  }
  int best = INF;
  vi matches(schildren, gchildren);
  iota(matches.begin(), matches.begin() + gchildren, 0);
  do {
    int res = 0;
    rep(i,0,schildren) res += costs[matches[i]][i];
    best = min(best, res);
  } while (next_permutation(all(matches)));
  return best;
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
