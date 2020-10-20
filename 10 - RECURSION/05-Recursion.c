/******************************************* OBJETIVO ******************************************************
 * Dado um vetor de inteiros e o seu número de elementos, inverta a posição dos seus elementos. Caso base:
 * Tamanho do array menor ou igual a 1; Passo da recursão: Troca o 1º e o último elementos e inverte resto
 * do array.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

void invert(int*, int, int);

int main(void) {
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
  printf("\nVetor invertido: \n");
  invert(arr, 0, 7);
  for(int i = 0; i < 8; i ++) {
    printf(" %d ", arr[i]);
  }
  printf("\n");
  return 0;
}

void invert(int arr[], int l_idx, int r_idx) {
  if(l_idx >= r_idx) return;
  int tmp = arr[l_idx];
  arr[l_idx] = arr[r_idx];
  arr[r_idx] = tmp;
  invert(arr, l_idx + 1, r_idx - 1);
}