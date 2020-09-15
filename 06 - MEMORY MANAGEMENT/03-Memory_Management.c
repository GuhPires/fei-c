/******************************************* OBJETIVO ******************************************************
 * Escreva um programa em C para alocar memória dinamicamente para armazenar N números inteiros inseridos
 * pelo usuário e, em seguida, exiba a soma de todos os N números.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n = 0, *nums, sum = 0;
  
  printf("Digite quantos números deseja inserir: ");
  scanf("%d", &n);
  nums = (int*)calloc(n, sizeof(int));
  if(nums == NULL) {
    printf("Memória não alocada!");
    return 0;
  }
  
  for(int i = 0; i < n; i++){
    printf("Digite o %dº número: ", i+1);
    scanf("%d", &nums[i]);
    sum += nums[i];
  }

  printf("A soma dos números digitados é: %d\n", sum);

  free(nums);

  return 0;
}