/******************************************* OBJETIVO ******************************************************
 * Escreva um programa que recebe quatro strings (sem utilizar o scanf()) que representam números reais
 * (float), converte as strings em reais (float), soma os valores e imprime o total dos quatro valores.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char num1[10], num2[10], num3[10], num4[10];
  puts("Digite 4 números reais (digite um e pressione ENTER)...");
  gets(num1);
  gets(num2);
  gets(num3);
  gets(num4);

  float n1 = atof(num1), n2 = atof(num2), n3 = atof(num3), n4 = atof(num4);

  printf("Soma dos 4 valores digitados: %f\n", n1 + n2 + n3 + n4);
  return 0;
}