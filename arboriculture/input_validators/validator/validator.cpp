#include "validator.h"

int maxB;
int readTree() {
  int B = Int(0, maxB); Space();
  vector<int> par = SpacedInts(B, 0, B - 1);
  for (int i = 0; i < B; i++) {
    assert(par[i] <= i);
  }
  return B;
}

void run() {
  maxB = Arg("maxB");
	int N = Int(1, 100); Space();
  int M = Int(N, 100); Endl();
  int branches = 0;
  for (int i = 0; i < N + M; i++) {
    branches += readTree();
  }
  assert(branches <= (int)Arg("maxTot"));
  Eof();
}
