/******************************************* OBJETIVO ******************************************************
 * Faça uma função que receba como parâmetro um vetor A com dez números reais e retorne esses números
 * ordenados de forma crescente.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include "sort.h"

int main(void) {
  int arr[10] = {2, 3, 1, 5, 4, 6, 9, 7, 8, 10};
  sort_array(arr, 10);
  puts("Sorted Array...");
  for(int i = 0; i < 10; i++) {
    printf("\t %d", arr[i]);
  }
  printf("\n");
  return 0;
}