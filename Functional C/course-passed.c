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

// cs136_passed(assign_mrks, assign_cnt, style, midterm, final, quizzes)
//   returns true if CS136 was passed, given the sum of all assignment marks
//   (assign_mrks), the number of submitted assignments (assign_cnt), the style
//   mark, midterm, final, and overall quiz mark (quizzes), and false
//   otherwise.
// requires: all parameters must be non-negative
//           assign_cnt must be smaller than 10
bool cs136_passed(int assign_mrks, int assign_cnt, int style,
                  int midterm, int final, int quizzes) {

  if (assign_cnt < 6) return false;

  if ( ( (2 * (assign_mrks + style) + (assign_cnt + 1)) /
         (2 * (assign_cnt + 1)) ) < 50 ) return false;

  if ( ( (2 * (25 * midterm + 50 * final) + 75) /
         (2 * 75) ) < 50 ) return false;

  return ( (2 * ( 20 * (assign_mrks + style)
                  + (25 * midterm + 50 * final + 5 * quizzes) * (assign_cnt + 1) )
            + (100 * (assign_cnt + 1))) /
           (2 * (100 * (assign_cnt + 1))) ) >= 50;
}

int main(void) {
  assert(cs136_passed(450, 9, 50, 50, 50, 50) == true);   
  assert(cs136_passed(450, 9, 50, 50, 40, 100) == false); 
  assert(cs136_passed(600, 5, 100, 100, 100, 100) == false);

  
  assert(cs136_passed(0, 6, 0, 100, 100, 100) == false); 
  assert(cs136_passed(900, 9, 100, 79, 35, 0) == true);


  trace_msg("All assertion-based tests passed!");
  return EXIT_SUCCESS;
}