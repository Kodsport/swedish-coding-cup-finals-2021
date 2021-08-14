#include "validator.h"

void run() {
  int maxB = Arg("maxB");
	int N = Int(1, 500); Space();
  int M = Int(N, 500); Endl();
  if ((int)Arg("singleTree")) {
    assert(N == 1 && M == 1);
  }
  int branches = 0;
  for (int i = 0; i < N + M; i++) {
    int B = Int(0, 1000);
    if (B) {
      Space();
      map<int, int> bs;
      vector<int> par = SpacedInts(B, 0, B - 1);
      for (int i = 0; i < B; i++) {
        bs[par[i]]++;
        assert(par[i] <= i);
      }
      for (auto it : bs) {
        assert(it.second <= maxB);
      }
    } else {
      Endl();
    }
  }
  Eof();
}
