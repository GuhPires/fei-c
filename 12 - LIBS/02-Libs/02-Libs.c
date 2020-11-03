/******************************************* OBJETIVO ******************************************************
 * Faça uma função que receberá dois números positivos por parâmetro e retorna a soma dos N números
 * inteiros existentes entre eles.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include "sum_btw.h"

int main(void) {
  int n1, n2;
  printf("Digite 2 números inteiros (separados por espaço): ");
  scanf("%d %d", &n1, &n2);
  printf("A soma dos números entre %d e %d é %d\n", n1, n2, sum_nums_btw(n1, n2));
  return 0;
}