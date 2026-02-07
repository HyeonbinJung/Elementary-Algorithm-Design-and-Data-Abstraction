/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement:
// https://student.cs.uwaterloo.ca/~cs136/current/assignments/integrity.shtml
/////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// None
//
// Name: Hyeonbin Jung
// login ID: h9jung
/////////////////////////////////////////////////////////////////////////////

#include "cs136.h"

// === Global constants =======================================================

// represents spicy chicken  [DO NOT CHANGE THIS VALUE]
const int SPICY = 1;
// represents mild chicken  [DO NOT CHANGE THIS VALUE]
const int MILD = 2;

// avoid magic numbers
const int FRIES_SERVINGS_PER_BATCH = 6;
const int FRIES_MINUTES_PER_BATCH_GROUP = 10;
const int FRIES_SIMULTANEOUS_BATCHES = 3;

const int CHICKEN_PIECES_PER_BATCH = 12;
const int CHICKEN_MINUTES_PER_BATCH_GROUP = 18;
const int CHICKEN_SIMULTANEOUS_BATCHES = 2;

// === Global variables (inventory) ==========================================

int inv_fries_servings = 0;
int inv_spicy_pieces = 0;
int inv_mild_pieces = 0;

// === Helper functions =======================================================

static bool valid_chicken_type(const int chicken_type) {
  return chicken_type == SPICY || chicken_type == MILD;
}

static int ceil_div(const int a, const int b) {
  // requires: b > 0, a >= 0
  return (a + b - 1) / b;
}

// === Core functions =========================================================

int make_fries(int batches) {
  if (batches < 1) {
    printf("Error: invalid amount of batches in make_fries!\n");
    return -1;
  }

  // inventory updates immediately
  inv_fries_servings += batches * FRIES_SERVINGS_PER_BATCH;

  // time: groups of up to 3 batches take 10 minutes each
  const int groups = ceil_div(batches, FRIES_SIMULTANEOUS_BATCHES);
  return groups * FRIES_MINUTES_PER_BATCH_GROUP;
}

int make_chicken(int batches, int chicken_type) {
  bool has_error = false;

  if (batches < 1) {
    printf("Error: invalid amount of batches in make_chicken!\n");
    has_error = true;
  }
  if (!valid_chicken_type(chicken_type)) {
    printf("Error: invalid chicken type in make_chicken!\n");
    has_error = true;
  }

  if (has_error) {
    return -1;
  }

  // inventory updates immediately
  const int pieces = batches * CHICKEN_PIECES_PER_BATCH;
  if (chicken_type == SPICY) {
    inv_spicy_pieces += pieces;
  } else { // MILD
    inv_mild_pieces += pieces;
  }

  // time: groups of up to 2 batches take 18 minutes each
  const int groups = ceil_div(batches, CHICKEN_SIMULTANEOUS_BATCHES);
  return groups * CHICKEN_MINUTES_PER_BATCH_GROUP;
}

bool prepare_order(int chicken_count, int chicken_type, int fries_count) {
  bool has_error = false;

  if (chicken_count < 0) {
    printf("Error: invalid count of chicken in order!\n");
    has_error = true;
  }
  if (!valid_chicken_type(chicken_type)) {
    printf("Error: invalid chicken type in order!\n");
    has_error = true;
  }
  if (fries_count < 0) {
    printf("Error: invalid count of fries in order!\n");
    has_error = true;
  }

  if (has_error) {
    return false;
  }

  int time_fries = 0;
  int time_chicken = 0;

  // fries: make minimum needed
  if (fries_count > inv_fries_servings) {
    const int needed = fries_count - inv_fries_servings;
    const int batches = ceil_div(needed, FRIES_SERVINGS_PER_BATCH);
    time_fries = make_fries(batches);
  }

  // chicken: make minimum needed (branch by type, no pointers)
  if (chicken_type == SPICY) {
    if (chicken_count > inv_spicy_pieces) {
      const int needed = chicken_count - inv_spicy_pieces;
      const int batches = ceil_div(needed, CHICKEN_PIECES_PER_BATCH);
      time_chicken = make_chicken(batches, SPICY);
    }
  } else { // MILD
    if (chicken_count > inv_mild_pieces) {
      const int needed = chicken_count - inv_mild_pieces;
      const int batches = ceil_div(needed, CHICKEN_PIECES_PER_BATCH);
      time_chicken = make_chicken(batches, MILD);
    }
  }

  const int time_total = (time_fries > time_chicken) ? time_fries : time_chicken;

  // Deduct from inventory (now sufficient)
  inv_fries_servings -= fries_count;
  if (chicken_type == SPICY) {
    inv_spicy_pieces -= chicken_count;
  } else {
    inv_mild_pieces -= chicken_count;
  }

  printf("Info: %d chicken and %d fries will be ready in %d minutes\n",
         chicken_count, fries_count, time_total);

  return true;
}

void print_inventory(void) {
  printf("======== INVENTORY ========\n");
  printf("Fries:            %4d servings\n", inv_fries_servings);
  printf("Chicken (SPICY):  %4d pieces\n", inv_spicy_pieces);
  printf("Chicken (MILD):   %4d pieces\n", inv_mild_pieces);
}

void discard_inventory(void) {
  inv_fries_servings = 0;
  inv_spicy_pieces = 0;
  inv_mild_pieces = 0;

  printf("Info: Stored food items discarded.\n");
}

void test_harness() {
  lookup_symbol("SPICY");
  lookup_symbol("MILD");
  const int CMD_MKFRIES = lookup_symbol("MKFRIES");
  const int CMD_MKCHICKEN = lookup_symbol("MKCHICKEN");
  const int CMD_ORDER = lookup_symbol("ORDER");
  const int CMD_PRINT = lookup_symbol("PRINT");
  const int CMD_DISCARD = lookup_symbol("DISCARD");
  int cmd = read_symbol();
  if (cmd == INVALID_SYMBOL) {
    return;
  }
  if (cmd == CMD_MKFRIES) {
    int batches = 0;
    if (1 == scanf("%d", &batches)) {
      if (-1 == make_fries(batches)) {
        return;
      }
    } else {
      printf("I/O Test Error: expecting integer!\n");
      return;
    }
  } else if (cmd == CMD_MKCHICKEN) {
    int type = read_symbol();
    int batches = 0;
    int retval = scanf("%d", &batches);
    if (1 != retval) {
      printf("I/O Test Error: expecting integer!\n");
      return;
    }
    if (-1 == make_chicken(batches, type)) {
      return;
    }
  } else if (cmd == CMD_ORDER) {
    int chicken_count = 0;
    if (1 != scanf("%d", &chicken_count)) {
      printf("I/O Test Error: expecting integer!\n");
      return;
    }
    int type = read_symbol();

    int fries_count = 0;
    if (1 != scanf("%d", &fries_count)) {
      printf("I/O Test Error: expecting integer!\n");
      return;
    } else {
      if (!prepare_order(chicken_count, type, fries_count)) {
        return;
      }
    }
  } else if (cmd == CMD_PRINT) {
    print_inventory();
  } else if (cmd == CMD_DISCARD) {
    discard_inventory();
  } else {
    printf("I/O Test Error: invalid command!\n");
    return;
  }
  test_harness();
}

int main(void) {
  test_harness();
}


