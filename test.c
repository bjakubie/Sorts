#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Automated.h"
#include "CUnit/Basic.h"
#include "sort.h"

void insertion_test_empty_set(){
  int tab[] = {};
  int tab1[] = {5}; //example of value
  int tab2[] = {3, 1};
  CU_ASSERT(RET_FAIL == insertion_sort( tab, 0 ));
  CU_ASSERT(RET_FAIL == insertion_sort( tab1, 1 ));
  CU_ASSERT(RET_SUCC == insertion_sort( tab2, 2 ));
}

void insertion_test_normal_set(){
  int tab[] = {12, 11, 19, 2, 92, 10, 15};
  int tab2[] = {2, 10, 11, 12, 15, 19, 92};
  CU_ASSERT(RET_SUCC == insertion_sort(tab, 7));
  int i;
  for ( i = 0 ; i < 7 ; i++ ) {
    CU_ASSERT_EQUAL(tab[i], tab2[i]);
  }
}

void insertion_test(){
  insertion_test_empty_set();
  insertion_test_normal_set();
}


void bubble_test_empty_set(){
  int tab[] = {};
  int tab1[] = {5}; //example of value
  int tab2[] = {3, 1};
  CU_ASSERT(RET_FAIL == bubble_sort( tab, 0 ));
  CU_ASSERT(RET_FAIL == bubble_sort( tab1, 1 ));
  CU_ASSERT(RET_SUCC == bubble_sort( tab2, 2 ));
}

void bubble_test_normal_set(){
  int tab[] = {12, 11, 19, 2, 92, 10, 15};
  int tab2[] = {2, 10, 11, 12, 15, 19, 92};
  CU_ASSERT(RET_SUCC == bubble_sort(tab, 7));
  int i;
  for ( i = 0 ; i < 7 ; i++ ) {
    CU_ASSERT_EQUAL(tab[i], tab2[i]);
  }
}

void bubble_test(){
  bubble_test_empty_set();
  bubble_test_normal_set();
}

int main (void) {
  CU_pSuite pSuite = NULL;

  /* initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry())
     return CU_get_error();

  /* add a suite to the registry */
  pSuite = CU_add_suite("Suite_1", NULL, NULL);
  if (NULL == pSuite) {
     CU_cleanup_registry();
     return CU_get_error();
  }

  if (( NULL == CU_add_test(pSuite, "BUBBLE_TEST", bubble_test) ) || ( NULL == CU_add_test(pSuite, "INSERTION_TEST", insertion_test) )){
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  //CU_basic_run_tests();
  CU_set_output_filename("out");
  CU_automated_run_tests();
  CU_cleanup_registry();
  return CU_get_error();

}
