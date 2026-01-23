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

// away_div(num, denom)
// integer division rounding away from zero
int away_div(int num, int denom) {
  assert(denom != 0);

  if (num == 0) {
    return 0;
  } else if ((num < 0 && denom > 0) || (num > 0 && denom < 0)) {
    // negative result: -ceil(|num|/|denom|)
    return -((abs(num) + abs(denom) - 1) / abs(denom));
  } else {
    // positive result: ceil(|num|/|denom|)
    return (abs(num) + abs(denom) - 1) / abs(denom);
  }
}

// num_pizzas(num_people, slices_per_pizza, slices_each)
// number of whole pizzas needed
int num_pizzas(int num_people, int slices_per_pizza, int slices_each) {
  assert(num_people >= 0);
  assert(slices_per_pizza > 0);
  assert(slices_each >= 0);

  if (num_people == 0 || slices_each == 0) {
    return 0;
  } else {
    return away_div(num_people * slices_each, slices_per_pizza);
  }
}

int main(void) {
  assert(away_div(39, 10) == 4);
  assert(num_pizzas(39, 10, 1) == 4);
  assert(away_div(-39, 10) == -4);
  assert(away_div(39, -10) == -4);
  assert(away_div(-39, -10) == 4);
  assert(away_div(0, 7) == 0);

  assert(num_pizzas(0, 10, 5) == 0);
  assert(num_pizzas(5, 8, 2) == 2);
}
