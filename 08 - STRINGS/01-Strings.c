/******************************************* OBJETIVO ******************************************************
 * Escreva um programa que recebe quatro strings (sem utilizar o scanf()) que representam números inteiros,
 * converte as strings em inteiros, soma os valores e imprime o total dos quatro valores.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char num1[5], num2[5], num3[5], num4[5];
  puts("Digite 4 números inteiros (digite um e pressione ENTER)...");
  gets(num1);
  gets(num2);
  gets(num3);
  gets(num4);

  int n1 = atoi(num1), n2 = atoi(num2), n3 = atoi(num3), n4 = atoi(num4);

  printf("Soma dos 4 valores digitados: %d\n", n1 + n2 + n3 + n4);
  return 0;
}