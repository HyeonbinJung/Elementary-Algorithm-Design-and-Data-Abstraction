/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// None
//
// Name: Hyeonbin Jung
// login ID: h9jung
//////////////////////////////////////////////////////////////////////////////////////////

#include "cs136.h"

// helper(min, max) reads from input, produces output at base case
void min_max_helper(int min, int max) {
  int val = 0;

  if (scanf("%d", &val) != 1) {
    // no more input → print result
    printf("min: %d / max: %d\n", min, max);
    return;
  }

  if (val < min) {
    min = val;
  }
  if (val > max) {
    max = val;
  }

  min_max_helper(min, max);
}

// print_min_max() Reads a non-empty sequence of integers 
// from input and prints the smallest and largest values after all input has been read.
void print_min_max(void) {
  int first = 0;

  // problem guarantees at least one number
  scanf("%d", &first);

  min_max_helper(first, first);
}

int main(void) {
  print_min_max();
  return EXIT_SUCCESS;
}