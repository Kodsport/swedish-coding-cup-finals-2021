#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

#define rep(i,a,b) for(ll i = a; i<b;i++)
#define per(i,a,b) for(ll i = a; i>=b; i--)
#define inf LLONG_MAX
#define all(x) x.begin(),x.end()
#define sz(x) (ll)(x).size()
#define trav(a,x) for(auto &a: x)
#define mp(x,y) make_pair(x,y)

int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(15) << fixed;
  ll n; cin >> n;
  vector<string> inp;
  string tmp;
  rep(i,0,n) { cin >> tmp; inp.push_back(tmp+" "); }
  string cur = inp[0];
  rep(i,1,n){
    cout << cur << endl;
    ll j = 0, k = 0;
    string nxt = "";
    while (j < sz(cur) && k < sz(inp[i])){
      if (inp[i][k] == cur[j]) { nxt += inp[i][k]; j++; k++; continue; }
      else {
        if (cur[j] == '{') {
          if (k < sz(inp[i])-1 && inp[i][k] == 'a' && inp[i][k+1] == 'a'){
            nxt += '{';
            j++; k += 2;
          } else {
            break;
          }
        } else {
          break;
        }
      }
    }
    ll tmp = sz(nxt);
    rep(l,k,sz(inp[i])) nxt += inp[i][l];
    k = tmp;
    if (inp[i][k]-' ' > cur[j]-' '){
      cur = nxt;
    } else {
      if (k == sz(nxt)-1) k--;
      while (k >= 0 && !(nxt[k] == 'a' && nxt[k+1] == 'a')) k--;
      if (k < 0) { cout << "no" << endl; exit(0); }
      cur = "";
      rep(l,0,sz(nxt)){
        if (l == k) continue;
        if (l == k+1) cur += '{';
        else cur += nxt[l];
      }
    }
  }
  cout << "yes" << endl;

}
