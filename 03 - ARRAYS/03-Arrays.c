/******************************************* OBJETIVO ******************************************************
 * Faça um programa para receber um vetor de 10 elementos (pedir para o usuário) e apresentar: a soma dos
 * ELEMENTOS pares e a soma dos elementos de ÍNDICE par
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main(void) {
  int even_sum = 0, even_idx_sum = 0, nums[10];

  printf("Por favor digite 10 números inteiros...\n");

  for(int i = 0; i < 10; i++) {
    printf("Digite o %dº número: ", i + 1);
    scanf("%d", &nums[i]);
    if(nums[i] % 2 == 0) {
      even_sum += nums[i];
    }
    if(i % 2 == 0) {
      even_idx_sum += nums[i];
    }
  }

  printf("Soma dos elementos pares é %d e a soma dos elementos que estão em índice par é %d.\n", even_sum, even_idx_sum);

  return 0;
}