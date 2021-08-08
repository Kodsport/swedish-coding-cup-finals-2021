#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

bool DEBUG = 0;
vi A;
int queries = 0;

int ask(int a, int b, int c, int d){
    queries++;
    if(!DEBUG){
        cout <<"? " <<  a << " " << b << " " << c << " " << d << "\n";
        fflush(stdout);
        int result;
        cin >> result;
        return result;
    }
    else{
        int sum1 = 0;
        int sum2 = 0;
        for(int c1 = a; c1 < b; c1++){
            sum1 += A[c1];
        }
        for(int c1 = c; c1 < d; c1++){
            sum2 += A[c1];
        }
        if(sum1 > sum2)return -1;
        if(sum1 < sum2)return 1;
        return 0;
    }
}

int solve(int a, int b, bool check = 1){
    if(a == b)return 0;
    if(check && ask(0,0,a,b) == 0)return 0;
    if(a == b-1)return 1;
    int x = a;
    int y = b;
    bool odd = 1;
    while(x < y-1){
        int mid = (x+y)/2;
        int temp = ask(a, mid, mid, b);
        if(temp == -1){
            y = mid;
        }
        else{
            x = mid;
            if(temp == 0){
                odd = 0;
                break;
            }
        }
    }

    if(odd){
        if(x-a < b-x){
            return 2*solve(a, x) + 1;
        }
        else{
            return 2*solve(x, b, 0) - 1;
        }
    }
    if(x-a < b-x){
        return 2*solve(a, x, 0);
    }
    return 2*solve(x, b, 0);
}

int main() {
    int n;
    cin >> n;
    int sum = 0;
    if(DEBUG){
        rep(c1,0,n){


            int a = rand()%2;

            A.push_back(a);
            sum += A.back();
        }
    }

    int ans = solve(0, n);
    cout << "! " << ans << "\n";
    fflush(stdout);

    if(DEBUG){
        cerr << "ANSWER: " << sum << "\n";
        cerr << "QUERIES: " << queries << "\n";
    }

    return 0;
}

