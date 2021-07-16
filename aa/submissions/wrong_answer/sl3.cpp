#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	char aa = (char)('z' + 1);
	string prev;
	cin >> prev;
	rep(i,0,N-1) {
		string w, w2;
		cin >> w;
		// cout << "looking at " << w << ", prev = " << prev << endl;
		int j = 0, j2 = 0, n = sz(w);
		while (j < n) {
			if (j2 == sz(prev)) {
				while (j < n) w2 += w[j++];
				goto ok;
			}
			char c = prev[j2];
			if (w[j] > c) {
				while (j < n) w2 += w[j++];
				goto ok;
			}

			if (w[j] == c) {
				w2 += c;
				j++;
				j2++;
				continue;
			}
			if (w[j] == 'a' && j+1 < n && w[j+1] == 'a') {
				if (c == aa) {
					w2 += c;
					j += 2;
					j2++;
					continue;
				} else if (0) { // BUG: missing this case
					w2 += c;
					j += 2;
					while (j < n) w2 += w[j++];
					goto ok;
				}
			}

			break;
		}
		assert(j2 != sz(prev)); // no duplicate words
		// bad sorting at position j2, adjust w2
		while (j < n) w2 += w[j++];
		for (int k = j2-1; k >= 0; k--) {
			if (w2[k] == 'a' && k+1 < sz(w2) && (w2[k+1] == 'a' || w2[k+1] == aa)) {
				string w3 = w2.substr(0, k);
				w3 += aa;
				if (w2[k+1] == aa) w3 += 'a';
				k += 2;
				while (k < j2) {
					char c = w2[k++];
					if (c == aa) w3 += 'a', w3 += 'a';
					else w3 += c;
				}
				w2 = move(w3);
				goto ok;
			}
		}
		cout << "no" << endl;
		return 0;
ok:
		prev = move(w2);
	}
	cout << "yes" << endl;
	exit(0);
}
