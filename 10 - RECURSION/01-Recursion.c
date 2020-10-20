/******************************************* OBJETIVO ******************************************************
 * Implemente o problema do número Fatorial de forma iterativa (utilize while, for ou do-while). Neste
 * exercício você não usará recursão, mas poderá comparar os duas técnicas e entender melhor quando
 * utilizar recursão.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int factorial(int);

int main(void) {
  int num = 0;
  puts("Digite um número inteiro: ");
  scanf("%d", &num);
  printf("O fatorial de %d é %d\n", num, factorial(num));
  return 0;
}

int factorial(int n) {
  int curr = n;
  int f = 1;
  while(curr > 0) {
    f *= curr;
    curr--;
  }
  return f;
}