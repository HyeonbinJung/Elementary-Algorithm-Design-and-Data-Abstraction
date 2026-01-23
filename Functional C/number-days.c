///////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Information & Policies > Academic Integrity Policy)
///////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// None
//
// Name: Hyeonbin Jung
// login ID: h9jung
///////////////////////////////////////////////////////////////////////////////



#include "cs136.h"

// number_days(s_yr, s_mth, s_day, e_yr, e_mth, e_day)
//   returns the number of days from the start date to the end date,
//   not including the ending date.
// requires:
//   s_yr, e_yr >= 1582
//   1 <= s_mth, e_mth <= 12
//   1 <= s_day <= days in s_mth of s_yr
//   1 <= e_day <= days in e_mth of e_yr
//   start date is not after end date

int number_days(int s_yr, int s_mth, int s_day,
                int e_yr, int e_mth, int e_day) {

  // requires
  assert(s_yr >= 1582 && e_yr >= 1582);
  assert(1 <= s_mth && s_mth <= 12);
  assert(1 <= e_mth && e_mth <= 12);
  assert(s_day >= 1 && e_day >= 1);

  if (s_yr == e_yr && s_mth == e_mth && s_day == e_day) {
    return 0;
  }

  if (s_mth == 2) {
    if ((s_yr % 4 == 0 && s_yr % 100 != 0) || (s_yr % 400 == 0)) {
      if (s_day < 29) {
        return 1 + number_days(s_yr, 2, s_day + 1,
                               e_yr, e_mth, e_day);
      } else {
        return 1 + number_days(s_yr, 3, 1,
                               e_yr, e_mth, e_day);
      }
    } else { // not leap
      if (s_day < 28) {
        return 1 + number_days(s_yr, 2, s_day + 1,
                               e_yr, e_mth, e_day);
      } else {
        return 1 + number_days(s_yr, 3, 1,
                               e_yr, e_mth, e_day);
      }
    }
  }

  if (s_mth == 4 || s_mth == 6 || s_mth == 9 || s_mth == 11) {
    if (s_day < 30) {
      return 1 + number_days(s_yr, s_mth, s_day + 1,
                             e_yr, e_mth, e_day);
    } else {
      return 1 + number_days(s_yr, s_mth + 1, 1,
                             e_yr, e_mth, e_day);
    }
  }

  if (s_day < 31) {
    return 1 + number_days(s_yr, s_mth, s_day + 1,
                           e_yr, e_mth, e_day);
  } else {
    if (s_mth == 12) {
      return 1 + number_days(s_yr + 1, 1, 1,
                             e_yr, e_mth, e_day);
    } else {
      return 1 + number_days(s_yr, s_mth + 1, 1,
                             e_yr, e_mth, e_day);
    }
  }
}

int main(void) {
  // public tests
  assert(number_days(1984, 1, 1, 1984, 3, 21) == 80);
  assert(number_days(2010, 1, 10, 2011, 2, 1) == 387);

  // add your own tests below
  assert(number_days(1984, 2, 28, 1984, 3, 1) == 2); 
  assert(number_days(1900, 2, 28, 1900, 3, 1) == 1);
  assert(number_days(2000, 2, 28, 2000, 3, 1) == 2); 
  assert(number_days(2020, 12, 31, 2021, 1, 1) == 1);
  return EXIT_SUCCESS;
}