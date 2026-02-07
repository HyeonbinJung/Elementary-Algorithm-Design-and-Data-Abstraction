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

// process Recursively reads all remaining integers, determines the global minimum and maximum, prints them once, 
// and then prints the values in reverse order while marking all minimum values.
static int process(const int cur, const int min, const int max) {
  int next = 0;

  if (1 != scanf("%d", &next)) {
    printf("min: %d / max: %d\n", min, max);

    if (cur == min) {
      printf("%d <-- MIN\n", cur);
    } else {
      printf("%d\n", cur);
    }
    return min; 
  }


  int new_min = (next < min) ? next : min;
  int new_max = (next > max) ? next : max;


  const int global_min = process(next, new_min, new_max);


  if (cur == global_min) {
    printf("%d <-- MIN\n", cur);
  } else {
    printf("%d\n", cur);
  }

  return global_min;
}

// print_min_max Reads a non-empty sequence of integers from standard input and invokes the recursive processing 
// to print the minimum and maximum values followed by the inputs in reverse order with all minimum values marked.
void print_min_max(void) {
  int first = 0;

  scanf("%d", &first);

  process(first, first, first);
}

int main(void) {
  print_min_max();
  return EXIT_SUCCESS;
}