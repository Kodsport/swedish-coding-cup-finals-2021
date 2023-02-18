#include "validator.h"

void run() {
	int n = Int(1, Arg("n"));
	Endl();

	int k = Arg("k");
	int cont = Arg("cont");

	vector<int> a = SpacedInts(n, 0, 1);
	int sum = 0;
	int streaks = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (a[i] == 1 && (i == 0 || a[i-1] == 0)) streaks++;
	}

	assert(sum <= k);
	if (cont) {
		assert(streaks <= 1);
	}
}
