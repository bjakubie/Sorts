#include "sort.h"

int bubble_sort(int *tab, int size){
  int i, j;
  int tmp;
  //size_t n = (int)sizeof(tab);

  if ( (2 < size ) && (TAB_MAX > size) ) {
    do {
      for ( j = 0 ; j < size-1 ; j++ ) {
        if ( tab[j] > tab[j+1] ) {
          tmp = tab[j];
          tab[j] = tab[j+1];
          tab[j+1] = tmp;
        }
      }
      size = size - 1;
    } while (size > 1);

    return RET_SUCC;
  }
  else if ( TAB_MAX < size ){
    printf("\ntoo many args to sort...");
    return RET_FAIL;
  }
  else {
    return RET_FAIL;
  }
}


/*
printf("HERE --> size = %d\n", size);
for ( i = 0 ; i < size ; i++){
  printf("arg[%d] = %d\n", i, tab[i]);
}
*/
