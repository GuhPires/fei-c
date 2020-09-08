/******************************************* OBJETIVO ******************************************************
 * Escreva um programa que declare um inteiro, um real, um char, e ponteiros para inteiro, real, e char.
 * Associe as variáveis aos ponteiros (use &). Modifique os valores de cada variável usando os ponteiros.
 * Imprima os valores das variáveis antes e após as modificações
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main(void) {
  int a = 10, *pA = &a;
  float b = 5.45, *pB = &b;
  char c = 'C', *pC = &c;

  printf("A: %d, pA: %p\n", a, pA);
  printf("B: %f, pB: %p\n", b, pB);
  printf("C: %c, pC: %p\n", c, pC);

  *pA = 22;
  *pB = 6.36;
  *pC = 'A';

  printf("New A: %d\n", a);
  printf("New B: %f\n", b);
  printf("New C: %c\n", c);

  return 0;
}