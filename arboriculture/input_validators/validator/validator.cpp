#include "validator.h"

void run() {
  int maxB = Arg("maxB");
	int N = Int(1, 100); Space();
  int M = Int(N, 100); Endl();
  int branches = 0;
  for (int i = 0; i < N + M; i++) {
    int B = Int(0, 100); Space();
    map<int, int> bs;
    vector<int> par = SpacedInts(B, 0, B - 1);
    for (int i = 0; i < B; i++) {
      bs[par[i]]++;
      assert(par[i] <= i);
    }
    for (auto it : bs) {
      assert(it.second <= maxB);
    }
  }
  Eof();
}
