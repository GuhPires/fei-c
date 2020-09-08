/******************************************* OBJETIVO ******************************************************
 * Implemente o código dado em C e preencha a tabela abaixo.
 * 
 *                  | a |  b  |   p1   |   p2   |
 *                  | 4 |  3  | end. A | end. A |
 *                  | 7 |  21 | end. A | end. A |
 *                  | 8 |  21 | end. B | end. A |
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main(void) {
  int a = 4, b = 3, *p1 = &a, *p2 = p1;
  // a -> 4, b -> 3, p1 -> end. A, -> end. A
  *p2 = *p1 + 3;
  // a -> 7
  b = b * (*p1);
  // b -> 21
  (*p2)++;
  // a -> 8
  p1 = &b;
  // p1 -> end. B
  printf("%d %d\n", *p1, *p2);
  printf("%d %d\n", a, b);
  return 0;
} 