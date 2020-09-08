/******************************************* OBJETIVO ******************************************************
 * Faça um programa para somar dois números reais utilizando ponteiros
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main(void) {
  float a, b, *pA = &a, *pB = &b;

  printf("Digite 2 números reais separados por espaço: ");
  scanf("%f %f", &a, &b);

  printf("Resultado da soma: %f \n", *pA + *pB);
  return 0;
}