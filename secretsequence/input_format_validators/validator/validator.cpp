#include "validator.h"

void run() {
	int n = Int(1, Arg("n"));
	Space();
	int d = Int(1, Arg("d"));
	Endl();

  vector<int> a = SpacedInts(n, 0, 1);
  int m = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    m += a[i];
    if (a[i] == 1 && (i == 0 || a[i-1] == 0)) cnt++;
  }

  assert(m <= stoi(Arg("k")));
  assert((!stoi(Arg("cont"))) || cnt <= 1);

}
