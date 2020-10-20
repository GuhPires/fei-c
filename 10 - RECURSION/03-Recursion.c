/******************************************* OBJETIVO ******************************************************
 * O máximo divisor comum dos números inteiros x e y é o maior número inteiro que divide igualmente x e y.
 * Escreva uma função recursiva mdc que retorne o maior divisor comum de x e y. O mdc de x e y é definido
 * recursivamente da seguinte forma: Se y é igual a 0, então mdc(x, y) é x; caso contrário, mdc(x, y) é
 * mdc(y, x% y), onde % é o operador de resto.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int mdc(int, int);

int main(void) {
  int x, y;
  printf("Digite 2 números separados por espaço para saber o MDC entre eles (EX: 10 2 para MDC de 10 e 2): ");
  scanf("%d %d", &x, &y);
  printf("O MDC de %d e %d é %d\n", x, y, mdc(x, y));
  return 0;
}

int mdc(int x, int y) {
  if(y == 0) {
    return x;
  }
  return mdc(y, x % y);
}