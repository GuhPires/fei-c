/******************************************* OBJETIVO ******************************************************
 * Faça um programa em C para criar dinamicamente memória para int, char e float. Teste o programa
 * recebendo e imprimindo valores para cada tipo.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *i = malloc(sizeof(int));
  float *f = malloc(sizeof(float));
  char *c = malloc(sizeof(char));

  printf("Digite um número inteiro: ");
  scanf("%d", i);
  printf("Digite um número real: ");
  scanf("%f", f);
  printf("Digite um caractere: ");
  scanf(" %c", c);

  printf("O inteiro: %d\n", *i);
  printf("O real: %f\n", *f);
  printf("O caractere: %c\n", *c);

  free(i);
  free(f);
  free(c);

  return 0;
}