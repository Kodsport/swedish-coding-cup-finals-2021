#include "validator.h"

void run() {
	int n = Int(1, Arg("n"));
	Endl();

	set<string> words;
	long long total = 0;
	string w;
	for (int i = 0; i < n; i++) {
		w.clear();
		for (;;) {
			char c = Char();
			if (c == '\n') break;
			assert('a' <= c && c <= 'z');
			total++;
			w += c;
		}
		assert(!w.empty());
		words.insert(w);
	}

	assert(total <= 500'000);
	assert((int)words.size() == n);
}
