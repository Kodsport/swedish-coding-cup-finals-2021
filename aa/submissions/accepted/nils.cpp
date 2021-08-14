#pragma GCC optimize("O3")   //
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 1000001;

vector<vi> words;

string alfa = "abcdefghijklmnopqrstuvwxyzZ";
bool ans = 1;

void solve(int i){
    int j = 0;
    int s1 = sz(words[i-1]);
    int s2 = sz(words[i]);
    bool ok = 0;
    rep(c1,0,min(s1, s2)){
        if(words[i-1][c1] < words[i][c1])return;
        if(words[i-1][c1] > words[i][c1]){
            if(c1 < s1-1 && c1 < s2-1 && words[i-1][c1] == 26 && words[i-1][c1+1] == 26 && words[i][c1] == 0 && words[i][c1+1] == 0){
                words[i][c1] = 26;
                words[i][c1+1] = 26;
            }
            else{
                break;
            }
        }
        j++;
    }

    if(j == s1)return;

    int lastaa = -1;
    rep(c1,0,min(j+1, s2-1)){
        if(words[i][c1] == 0 && words[i][c1+1]%26 == 0){
            lastaa = c1;
        }
    }

    if(lastaa == -1){ans = 0;return;}
    words[i][lastaa] = 26;
    words[i][lastaa+1] = 26;
    rep(c1,lastaa+2,s2){
        if(words[i][c1] == 26)words[i][c1] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n;
    rep(c1,0,n){
        string s;
        cin >> s;
        vi word;
        trav(c, s){
            word.push_back(c-'a');
        }
        words.push_back(word);
    }

    rep(c1,1,n){
        solve(c1);
    }

/*
    rep(c1,0,n){
        trav(c, words[c1]){
            cerr << alfa[c];
        }cerr << "\n";
    }
*/
    if(ans){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}
