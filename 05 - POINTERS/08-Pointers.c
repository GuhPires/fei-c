/******************************************* OBJETIVO ******************************************************
 * Crie um programa que contenha um vetor de inteiros contendo 5 elementos. Utilizando apenas aritmética de
 * ponteiros, leia este vetor pelo teclado e imprima o dobro de cada valor lido
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main(void) {
  int v[5], *aux = v;

  printf("Digite o 1º número: ");
  scanf("%d", aux);
  aux += 4;
  printf("Digite o 2º número: ");
  scanf("%d", aux);
  aux += 4;
  printf("Digite o 3º número: ");
  scanf("%d", aux);
  aux += 4;
  printf("Digite o 4º número: ");
  scanf("%d", aux);
  aux += 4;
  printf("Digite o 5º número: ");
  scanf("%d", aux);

  printf("Dobro dos valores digitados: \n");
  printf("[ %d ", *(aux - 16) * 2);
  printf("%d ", *(aux - 12) * 2);
  printf("%d ", *(aux - 8) * 2);
  printf("%d ", *(aux - 4) * 2);
  printf("%d ]\n", *aux * 2);

  return 0;
}