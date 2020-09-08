/******************************************* OBJETIVO ******************************************************
 * Crie um programa que deve armazenar uma palavra com 5 letras e apresentá-la, através do uso de ponteiros
 * char. Faça um ponteiro por letra
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main(void) {
  char a, b, c, d, e, *pA = &a, *pB = &b, *pC = &c, *pD = &d, *pE = &e;

  printf("Digite a 1ª letra: ");
  scanf(" %c", &a);
  printf("Digite a 2ª letra: ");
  scanf(" %c", &b);
  printf("Digite a 3ª letra: ");
  scanf(" %c", &c);
  printf("Digite a 4ª letra: ");
  scanf(" %c", &d);
  printf("Digite a 5ª letra: ");
  scanf(" %c", &e);

  printf("\nAs letras da palavra digitada e seus endereços:\n");
  printf("Letra: %c\tEndereço: %p\n", *pA, pA);
  printf("Letra: %c\tEndereço: %p\n", *pB, pB);
  printf("Letra: %c\tEndereço: %p\n", *pC, pC);
  printf("Letra: %c\tEndereço: %p\n", *pD, pD);
  printf("Letra: %c\tEndereço: %p\n", *pE, pE);
  return 0;
}