/******************************************* OBJETIVO ******************************************************
 * Escreva um programa em C para encontrar o máximo entre dois números usando operador ternário.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main(void) {
  int n1,n2;
  printf("Digite 2 números inteiros (separados por espaço): ");
  scanf("%d %d", &n1, &n2);
  n1 > n2 ? printf("O nº %d é maior número entre os digitados\n", n1) : printf("O nº %d é maior número entre os digitados\n", n2);
}