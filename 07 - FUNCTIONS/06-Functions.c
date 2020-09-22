/******************************************* OBJETIVO ******************************************************
 * Escreva uma função chamada triplo que recebe três números reais a, b e c passados por “referência". Sua
 * função deve “retornar” em a, b e c o triplo de cada valor.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

void triple(int*, int*, int*);

int main(void) {
  int a = 3, b = 4, c = 5;
  triple(&a, &b, &c);
  printf("Triplo: %d, %d, %d\n", a, b, c);
  return 0;
}

void triple(int *a, int *b, int *c){
  *a *= 3;
  *b *= 3;
  *c *= 3;
}