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
  ll cnt = 0;
  rep(i,0,n){
    if (ask(0,0,i,i+1)) cnt++;
  }
  cout << "! " << cnt << endl;
}
