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

ll ask(ll a, ll b, ll c, ll d){
  cout << "? " << a << " " << b << " " << c << " " << d << endl;
  ll ans; cin >> ans;
  return ans;
}

ll solve(ll lo, ll hi){
  if (lo == hi){
    ll x = ask(0,0,lo,hi+1);
    if (x) return 1;
    else return 0;
  } else if (lo > hi) {
    return 0;
  }
  ll a = 2*lo, b = 2*hi;
  ll mid = (a+b)/2;
  ll x = ask(lo, (mid+1)/2, mid/2+1, hi+1);
  while (x){
    if (x == -1) b = mid-1;
    else if (x == 1) a = mid+1;
    mid = (a+b)/2;
    x = ask(lo, (mid+1)/2, mid/2+1, hi+1);
  }
  ll tmp;
  tmp = solve(lo,(mid+1)/2-1);
  if (mid%2) {
    return 2*tmp;
  } else {
    if (ask(0,0,mid/2,mid/2+1)) return 2*tmp+1;
    else return 2*tmp;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(15) << fixed;
  ll n; cin >> n;
  ll ans = solve(0,n-1);
  cout << "! " << ans << endl;
}
