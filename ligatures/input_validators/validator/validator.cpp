#include "validator.h"

void run() {
	int n = Int(1, 1'000'000);
	Space();
	int q = Int(1, 100'000);
	Space();
	int k = Int(1, Arg("k"));
	Endl();

	for (int i = 0; i < n; i++) {
		char c = Char();
		assert('a' <= c && c <= 'z');
	}
	Endl();

	for (int qi = 0; qi < q; qi++) {
		map<pair<char,char>, int> seen;
		for (int i = 0; i < k; i++) {
			char c = Char();
			char d = Char();
			assert('a' <= c && c <= 'z');
			assert('a' <= d && d <= 'z');
			pair<char,char> pa{c,d};
			assert(!seen[pa]++);
		}
		Endl();
	}
}
