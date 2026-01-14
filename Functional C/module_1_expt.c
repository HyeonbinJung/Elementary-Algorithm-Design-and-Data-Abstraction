// This program computes b^n using recursion.

#include "cs136.h"

// expt(b, n) returns b raised to the power n.
// requires: n >= 0
int expt(int b, int n) {
  if (n == 0) {
    return 1;          
  } else {
    return b * expt(b, n - 1);
  }
}

int main(void) {
  assert(expt(2, 2) == 4);
  assert(expt(3, 0) == 1);
  assert(expt(0, 0) == 1);
  assert(expt(0, 4) == 0);

  trace_msg("Passed assertion tests");
}