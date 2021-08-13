#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i,a,b) for(ll i = a; i<b;i++)

int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(15) << fixed;
  ll n,d; cin >> n >> d;
  ll cnt = 0, tmp;
  rep(i,0,n) { cin >> tmp; cnt += tmp; }
  cout << cnt << endl;
}
