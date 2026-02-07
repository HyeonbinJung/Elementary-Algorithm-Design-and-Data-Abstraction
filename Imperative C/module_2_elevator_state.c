// elevator_state.c
// Tracks an elevator's floor and occupancy using global state.
// Provides three operations:
//   set_floor(n): move to floor n if n is within [min_floor, max_floor]
//   enter(n): add n passengers if it does not exceed max_capacity
//   leave(n): remove n passengers if n <= current occupancy
// Each operation prints either a warning message (and does not change state)
// or a success message (and updates state).

#include "cs136.h"

///////////////////////////
// ELEVATOR CONFIGURATION
// DO NOT EDIT THESE CONSTANTS
//
const int max_capacity = 15;
const int max_floor = 10;
const int min_floor = 0;
//
// END OF "DO NOT EDIT" ZONE
///////////////////////////

int elevator_occ = 0;
int elevator_floor = 0;

// set_floor(n) may mutate elevator_floor produces output
void set_floor(const int n) {
  if (n < min_floor || n > max_floor) {
    printf("WARNING! Invalid Floor!\n");
  } else {
    elevator_floor = n;
    printf("You have reached floor %d.\n", elevator_floor);
  }
}

// enter(n) may mutate elevator_occ produces output
// requires: n >= 0
void enter(const int n) {
  assert(n >= 0);
  if (elevator_occ + n > max_capacity) {
    printf("WARNING! Over Capacity!\n");
  } else {
    elevator_occ += n;
    printf("The number of passengers is %d.\n", elevator_occ);
  }
}

// leave(n) may mutate elevator_occ produces output
// requires: n >= 0
void leave(const int n) {
  assert(n >= 0);
  if (n > elevator_occ) {
    printf("WARNING! Invalid Leave!\n");
  } else {
    elevator_occ -= n;
    printf("The number of passengers is %d.\n", elevator_occ);
  }
}

int main(void) {
  assert(elevator_floor == 0);
  set_floor(0);
  assert(elevator_floor == 0);
  set_floor(10);
  assert(elevator_floor == 10);

  elevator_occ = 0;
  assert(elevator_occ == 0);

  enter(0);                   
  assert(elevator_occ == 0);

  enter(15);                 
  assert(elevator_occ == 15);

  enter(0);                  
  assert(elevator_occ == 15);

  enter(1);                   
  assert(elevator_occ == 15);

  elevator_occ = 0;
  assert(elevator_occ == 0);

  enter(16);             
  assert(elevator_occ == 0);

  enter(1);                
  assert(elevator_occ == 15);

  elevator_occ = 14;
  assert(elevator_occ == 14);

  enter(2);                   
  assert(elevator_occ == 14);


  elevator_occ = 0;
  assert(elevator_occ == 0);

  leave(0);                
  assert(elevator_occ == 0);

  leave(1);                   
  assert(elevator_occ == 0);

  elevator_occ = 5;
  assert(elevator_occ == 5);

  leave(0);                   
  assert(elevator_occ == 5);

  leave(5);                  
  assert(elevator_occ == 0);


  trace_msg("Passed assertion tests");
}