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

// forward declarations (prototypes)
void print_stars(const int n);
void print_rows(const int width, const int height);

// print_stars(n) produces output prints n '*' then newline
void print_stars(const int n) {
  if (0 == n) {
    printf("\n");
    return;
  } else {
    printf("*");
    print_stars(n - 1);
  }
}

// print_rows(width, height) prints height rows, each with width stars
void print_rows(const int width, const int height) {
  if (0 == height) {
    return;
  } else {
    print_stars(width);
    print_rows(width, height - 1);
  }
}

void print_rectangles(void) {
  int width = 0;
  int height = 0;

  if (1 != scanf("%d", &width)) {
    return;
  }
  if (1 != scanf("%d", &height)) {
    return;
  }


  print_rows(width, height);
}

int main(void) {
  print_rectangles();
}