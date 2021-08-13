#pragma GCC target ("avx2")
#include <iostream>
#include <vector>
#include <string>
#include <immintrin.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int SIMD_BITS = 256;
const int MAXQ = 100'000;

typedef __m256i mi;

void set_bit(mi& m, size_t ind) {
	union {
		mi m;
		uint32_t ar[SIMD_BITS / 32];
	} u;
	u.m = m;
	u.ar[ind / 32] = (uint32_t) (u.ar[ind / 32] | (1 << (ind % 32)));
	m = u.m;
}

void printm(mi m) {
	union {
		mi m;
		uint32_t ar[SIMD_BITS / 32];
	} u;
	u.m = m;
	rep(i,0,SIMD_BITS) {
		cout << ((u.ar[i / 32] >> (i % 32)) & 1);
	}
	cout << endl;
}


mi active[MAXQ / SIMD_BITS + 1][26*26+1]{}; // ~26*26 * MAXQ / 8 bytes

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N, Q, K;
	cin >> N >> Q >> K;
	string str, s;
	cin >> str;
	N--;
	int padN = (N + 31) & -32;
	int qchunks = Q / SIMD_BITS + 1;
	vector<short> pairs(padN);
	rep(i,0,N) {
		int a = str[i] - 'a';
		int b = str[i+1] - 'a';
		pairs[i] = (short)((26*a + b) * sizeof(mi));
	}
	rep(i,N,padN) {
		pairs[i] = 26*26 * sizeof(mi);
	}

	rep(i,0,Q) {
		cin >> s;
		rep(j,0,K) {
			int a = s[2*j] - 'a';
			int b = s[2*j+1] - 'a';
			set_bit(active[i / SIMD_BITS][26*a + b], i % SIMD_BITS);
		}
	}

	vi res(qchunks * SIMD_BITS);
	rep(k,0,qchunks) {
		char* act = (char*)active[k];
		int i = 0;
		mi zero = _mm256_setzero_si256();
		mi acc0 = zero, acc1 = zero, acc2 = zero, acc3 = zero, acc4 = zero;
		mi accs[30]{}, ts[30]{};
		mi picked = zero;
		mi carry;
#define SET0 carry = picked = _mm256_andnot_si256(picked, *(mi*)(act + pairs[i++]))
#define ADD2(t, acc) { mi x = t ^ carry, y = (x & acc) | (t & carry); acc = x ^ acc, carry = y; } // (carry, acc) = (t + acc + carry)
#define ADD(ind) ADD2(t ## ind, acc ## ind)
		while (i < padN) {
			mi t0, t1, t2, t3, t4;
			SET0; t0 = carry;
			SET0; ADD(0); t1 = carry;
			SET0; t0 = carry;
			SET0; ADD(0); ADD(1); t2 = carry;
			SET0; t0 = carry;
			SET0; ADD(0); t1 = carry;
			SET0; t0 = carry;
			SET0; ADD(0); ADD(1); ADD(2); t3 = carry;
			SET0; t0 = carry;
			SET0; ADD(0); t1 = carry;
			SET0; t0 = carry;
			SET0; ADD(0); ADD(1); t2 = carry;
			SET0; t0 = carry;
			SET0; ADD(0); t1 = carry;
			SET0; t0 = carry;
			SET0; ADD(0); ADD(1); ADD(2); ADD(3); t4 = carry;
			SET0; t0 = carry;
			SET0; ADD(0); t1 = carry;
			SET0; t0 = carry;
			SET0; ADD(0); ADD(1); t2 = carry;
			SET0; t0 = carry;
			SET0; ADD(0); t1 = carry;
			SET0; t0 = carry;
			SET0; ADD(0); ADD(1); ADD(2); t3 = carry;
			SET0; t0 = carry;
			SET0; ADD(0); t1 = carry;
			SET0; t0 = carry;
			SET0; ADD(0); ADD(1); t2 = carry;
			SET0; t0 = carry;
			SET0; ADD(0); t1 = carry;
			SET0; t0 = carry;
			SET0; ADD(0); ADD(1); ADD(2); ADD(3); ADD(4);

			int ind = 5;
			while (!(i & (1 << ind))) {
				ADD2(ts[ind], accs[ind]);
				ind++;
			}
			ts[ind] = carry;
		}
		accs[0] = acc0;
		accs[1] = acc1;
		accs[2] = acc2;
		accs[3] = acc3;
		accs[4] = acc4;

		carry = zero;
		rep(ind,0,30) {
			mi val = (padN & (1 << ind) ? ts[ind] : zero);
			ADD2(val, accs[ind]);
		}

		mi low32 = _mm256_set1_epi32(1);
		rep(j,0,32) {
			mi mval = zero, p2 = low32;
			rep(ind,0,30) {
				mval = _mm256_add_epi32(mval, _mm256_and_si256(_mm256_sub_epi32(zero, accs[ind] & low32), p2));
				accs[ind] = _mm256_srli_epi32(accs[ind], 1);
				p2 = _mm256_slli_epi32(p2, 1);
			}
			union {
				mi m;
				uint32_t ar[SIMD_BITS / 32];
			} u;
			u.m = mval;
			rep(l,0,SIMD_BITS / 32) {
				res[k * SIMD_BITS + l * 32 + j] = u.ar[l];
			}
		}
	}

	rep(i,0,Q)
		cout << res[i] << '\n';
	cout << flush;

	exit(0);
}
