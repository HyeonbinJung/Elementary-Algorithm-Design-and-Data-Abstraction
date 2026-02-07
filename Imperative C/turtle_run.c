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

// Global constants (avoid magic numbers)
const int CMD_UP = 1;
const int CMD_DOWN = 2;
const int CMD_LEFT = 3;
const int CMD_RIGHT = 4;

const int START_POS = 0;
const int ONE = 1;

static void print_island_rows(const int width, const int height,
                              const int T_col, const int T_row,
                              const int cur_row);

static void print_island_cols(const int width,
                              const int T_col, const int T_row,
                              const int cur_col, const int cur_row);

static void turtle_process(const int width, const int height,
                           const int T_col, const int T_row);

// print_island(width, height, T_col, T_row) produces output
// requires: width, height > 0; T_col, T_row >= 0
void print_island(int width, int height, int T_col, int T_row) {
  assert(width > 0);
  assert(height > 0);
  assert(T_col >= 0);
  assert(T_row >= 0);

  print_island_rows(width, height, T_col, T_row, 0);
  printf("The turtle is at (%d, %d).\n", T_col, T_row);
}

// prints rows [cur_row .. height-1]
static void print_island_rows(const int width, const int height,
                              const int T_col, const int T_row,
                              const int cur_row) {
  if (cur_row == height) {
    return;
  } else {
    print_island_cols(width, T_col, T_row, 0, cur_row);
    printf("\n");
    print_island_rows(width, height, T_col, T_row, cur_row + 1);
  }
}

// prints columns [cur_col .. width-1] for a fixed row cur_row
static void print_island_cols(const int width,
                              const int T_col, const int T_row,
                              const int cur_col, const int cur_row) {
  if (cur_col == width) {
    return;
  } else {
    if (cur_col == T_col && cur_row == T_row) {
      printf("T");
    } else {
      printf("*");
    }
    print_island_cols(width, T_col, T_row, cur_col + 1, cur_row);
  }
}

// turtle_run() reads input, produces output
// requires: input provides at least two ints: width height, both positive
void turtle_run(void) {
  int width = 0;
  int height = 0;

  if (1 != scanf("%d", &width)) return;
  if (1 != scanf("%d", &height)) return;

  assert(width > 0);
  assert(height > 0);

  print_island(width, height, START_POS, START_POS);

  turtle_process(width, height, START_POS, START_POS);
}


static void turtle_process(const int width, const int height,
                           const int T_col, const int T_row) {
  int cmd = 0;
  if (1 != scanf("%d", &cmd)) {
    return; 
  }

  int new_col = T_col;
  int new_row = T_row;

  if (cmd == CMD_UP) {
    new_row = (T_row + height - ONE) % height;
  } else if (cmd == CMD_DOWN) {
    new_row = (T_row + ONE) % height;
  } else if (cmd == CMD_LEFT) {
    new_col = (T_col + width - ONE) % width;
  } else if (cmd == CMD_RIGHT) {
    new_col = (T_col + ONE) % width;
  } else {
    return; 
  }

  print_island(width, height, new_col, new_row);
  turtle_process(width, height, new_col, new_row);
}

int main(void) {
  turtle_run();
  return EXIT_SUCCESS;
}