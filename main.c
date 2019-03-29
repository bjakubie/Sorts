#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main (int argc, char *argv[]){
  int *arg_tab;

  if ( 2 >= argc ) {
    printf("I do not have anything to sort... \n");
    return -1;
  }
  else {
    int i;
    arg_tab = (int *) malloc(sizeof(int) * (argc - 1));
    for ( i = 0; i < argc - 1 ; i++ ) {
      arg_tab[i] = atoi(argv[i+1]);
    }
  }

  bubble_sort(arg_tab, argc-1);

  free(arg_tab);
  return 0;
}


/*
int i;
printf("AFTER BUBBLE\n");
for ( i = 0 ; i < argc - 1 ; i++ ) {
  printf("arg_tab[%d] = %d\n", i, arg_tab[i] );
}
*/
