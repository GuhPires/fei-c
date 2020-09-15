/******************************************* OBJETIVO ******************************************************
 * Faça um programa que crie um vetor de tamanho 10 dinamicamente por ponteiros.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *v = (int*)calloc(10, sizeof(int));

  if(v == NULL) {
    printf("Memória não foi alocada com sucesso.\n");
    return 0;
  }

  printf("Vetor alocado dinamicamente com sucesso!\n");

  free(v);
  return 0;
}