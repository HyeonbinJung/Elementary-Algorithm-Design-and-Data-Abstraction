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

// next_hailstone(num) returns the next hailstone value after num
// requires: num > 0
int next_hailstone(int num) {
  assert(num > 0);
  if (num % 2 == 0) {
    return num / 2;
  } else {
    return 3 * num + 1;
  }
}

// nth_hailstone(num, n) finds the n-th hailstone number of a given num
// Convention: the 1st hailstone number is num itself.
// requires: num > 0, n > 0
int nth_hailstone(int num, int n) {
  assert(num > 0);
  assert(n > 0);

  if (n == 1) {
    return num;
  } else {
    return nth_hailstone(next_hailstone(num), n - 1);
  }
}

int main(void) {
  assert(nth_hailstone(5, 3) == 8);  
  assert(nth_hailstone(11, 6) == 13);  
  assert(nth_hailstone(5, 1) == 5);
  assert(nth_hailstone(5, 4) == 4);
  assert(nth_hailstone(11, 1) == 11);
  assert(nth_hailstone(11, 2) == 34);
  assert(nth_hailstone(11, 7) == 40);
  assert(nth_hailstone(1, 1) == 1);
  assert(nth_hailstone(1, 2) == 4);   

  return EXIT_SUCCESS;
}