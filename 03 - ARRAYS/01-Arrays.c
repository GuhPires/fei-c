/******************************************* OBJETIVO ******************************************************
 * Crie um programa em C que peça 10 números reais, armazene-os em um vetor e diga qual é o índice do
 * maior, e seu valor.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main (void) {
  int higher[2] = {0, 0}, nums[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  printf("Por favor digite 10 números inteiros...\n");

  for(int i = 0; i < 10; i++) {
    printf("Digite o %dº número: ", i + 1);
    scanf("%d", &nums[i]);
    printf("I: %d\n", i);
    if(nums[i] > higher[1]) {
      higher[0] = i;
      higher[1] = nums[i];
    }
  }

  printf("O maior valor é %d e está no índice %d.\n", higher[1], higher[0]);

  return 0;
}