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

int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(15) << fixed;
  ll n; cin >> n;
  ll a = 0, b = 2*(n-1);
  ll mid = (a+b)/2;
  ll x = ask(0, (mid-1)/2+1, mid/2+1, n);
  while (x){
    if (x == -1) b = mid-1;
    else if (x == 1) a = mid+1;
    mid = (a+b)/2;
    x = ask(0, (mid-1)/2+1, mid/2+1, n);
  }

  ll ans = 0;
  a = 0, b = (mid-1)/2;
  ll c = mid/2+1, d = n-1;
  if (c-b == 2){
    if (ask(0,0,b+1,b+2)) ans++;
  }
  if (c == n) {
    cout << "! " << ans << endl;
  } else if (!ask(0,0,c,c+1)){
    cout << "! " << ans << endl;
  } else if (ask(0,0,d,d+1)){
    cout << "! " << ans + 2*(d-c+1) << endl;
  } else {
    ll t = (c+d)/2;
    while (c+1 < d){
      if (ask(0,0,t,t+1)){
        c = t;
      } else {
        d = t;
      }
      t = (c+d)/2;
    }
    cout << "! " << ans + 2*(c-mid/2) << endl;
  }
}
