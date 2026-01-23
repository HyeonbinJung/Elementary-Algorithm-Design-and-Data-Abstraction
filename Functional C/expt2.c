/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// I received help from and/or collaborated with:
// NONE
//
// Name: Hyeonbin Jung
// login ID: h9jung
//////////////////////////////////////////////////////////////////////////////////////////

#include "cs136.h"

// helper function for accumulative recursion
int expt2_acc_helper(int n, int acc) {
  if (n == 0) {
    return acc;
  } else {
    return expt2_acc_helper(n - 1, acc * 2);
  }
}

// expt2_acc(n) returns 2^n using accumulative recursion.
// requires: n must be non-negative
int expt2_acc(int n) {
  assert(n >= 0);
  return expt2_acc_helper(n, 1);
}

int main(void) {
  assert(expt2_acc(3) == 8);
  assert(expt2_acc(0) == 1);
  assert(expt2_acc(1) == 2);
  assert(expt2_acc(5) == 32);
  assert(expt2_acc(10) == 1024);

  return EXIT_SUCCESS;
}