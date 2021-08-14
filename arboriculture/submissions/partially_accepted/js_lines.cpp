#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

  int goals, starts, ignore;
  cin >> goals >> starts;
  multiset<int> ss;
  vector<int> gs(goals);
  rep(i,0,goals) {
    int B;
    cin >> B;
    gs[i] = B;
    rep(j,0,B) cin >> ignore;
  }
  rep(i,0,starts) {
    int B;
    cin >> B;
    ss.insert(B);
    rep(j,0,B) cin >> ignore;
  }
  int res = 0;
  for (auto it : gs) {
    auto match = ss.find(it);
    if (match == ss.end()) {
      res++;
    } else {
      ss.erase(match);
    }
  }
  cout << res << endl;
}
