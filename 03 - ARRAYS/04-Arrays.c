/******************************************* OBJETIVO ******************************************************
 * Faça um programa para receber um vetor de 10 elementos inteiros e apresentar todos os conteúdos que
 * forem maiores que a soma de dois de seus antecessores
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main(void){
  // Só é possível analisar os dois antecessores a partir do índex 2, por isso bigger tem 8 posições.
  int nums[10], bigger[8] = {0, 0, 0, 0, 0, 0, 0, 0}, lst_bigger_idx = 0;

  printf("Por favor digite 10 números inteiros...\n");

  for(int i = 0; i < 10; i++) {
    printf("Digite o %dº número: ", i + 1);
    scanf("%d", &nums[i]);
    if(i > 1) {
      if(nums[i] > nums[i - 1] + nums[i - 2]){
        bigger[lst_bigger_idx] = nums[i];
        lst_bigger_idx ++;
      }
    }
  }

  printf("Elementos maiores que a soma de 2 de seus antecessores...\n");

  for(int i = 0; i < lst_bigger_idx; i++) {
    printf("%d ", bigger[i]);
  }
  printf("\n");
  
  return 0;
}