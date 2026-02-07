// print_forward_reverse.c
// Reads integers from standard input and prints them
// first in the order read, then in reverse order.

#include "cs136.h"

// print_forward_reverse(void) reads integers from input 
// return reverse and input

void print_forward_reverse(void) {
  int n;

  if (scanf("%d", &n) != 1) {
    return;
  }

  printf("%d\n", n);

  print_forward_reverse();

  printf("%d\n", n);
}

int main(void) {
  print_forward_reverse();
}