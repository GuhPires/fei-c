/******************************************* OBJETIVO ******************************************************
 * Escreva um programa que contenha duas variáveis inteiras. Leia o valor dessas variáveis pelo teclado. Em
 * seguida, compare seus endereços e exiba o conteúdo do maior endereço
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main(void) {
  int a, b;

  printf("Digite 2 números inteiros separados por espaço: ");
  scanf("%d %d", &a, &b);

  if(&a > &b) {
    printf("Maior endereço é %p, com o valor de %d\n", &a, a);
  } else {
    printf("Maior endereço é %p, com o valor de %d\n", &b, b);
  }

  return 0;
}