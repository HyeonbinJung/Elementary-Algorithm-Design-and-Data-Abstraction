// This program computes a CS 136 final grade from the four weighted components.
// Weights: concept checks 5%, assignments 25%, midterm 20%, final 50%.
// The final grade is rounded down (toward zero) exactly once in the final step.

#include "cs136.h"

// cs136_grade(concept_checks, assignments, midterm, final) returns the final CS 136
// grade using the given component grades and the course weights.
// requires: 0 <= concept_checks <= 100
// requires: 0 <= assignments <= 100
// requires: 0 <= midterm <= 100
// requires: 0 <= final <= 100
int cs136_grade(int concept_checks, int assignments, int midterm, int final) {
  assert(0 <= concept_checks && concept_checks <= 100);
  assert(0 <= assignments && assignments <= 100);
  assert(0 <= midterm && midterm <= 100);
  assert(0 <= final && final <= 100);
  
  return (5 * concept_checks + 25 * assignments + 20 * midterm + 50 * final) / 100;
}

int main(void) {
  assert(cs136_grade(4, 4, 4, 4) == 4);
  assert(cs136_grade(100, 100, 100, 100) == 100);
  assert(cs136_grade(100, 100, 100, 99) == 99);
  assert(cs136_grade(80, 60, 70, 90) == 78);
  assert(cs136_grade(0, 0, 0, 0) == 0);

  trace_msg("Passed assertion tests");
}