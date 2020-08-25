/******************************************* OBJETIVO ******************************************************
 * Faça um programa que imprime uma sequência de n números em ordem inversa à da leitura.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main(void) {
  int n;

  printf("Digite o número de elementos que deseja digitar: ");
  scanf("%d", &n);

  int nums[n];

  printf("Agora digite %d números inteiros...\n", n);
  for(int i = 0; i < n; i++) {
    printf("Digite o %dº número: ", i + 1);
    scanf("%d", &nums[i]);
  }

  for(int i = n - 1; i >= 0; i--){
    printf("%dº número é %d.\n", i + 1, nums[i]);
  }
  
  return 0;
}