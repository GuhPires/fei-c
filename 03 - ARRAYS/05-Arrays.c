/******************************************* OBJETIVO ******************************************************
 * Faça um programa que mostra o menor valor dentro do vetor T={1, 7 ,2 ,4}
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main(void) {
  int t[] = {1, 7, 2, 4}, smallest = 0;

  for(int i = 0; i < 4; i++){
    if(t[i] < smallest || i == 0){
      smallest = t[i];
    }
  }

  printf("O menor número entre [1, 7, 2, 4] é %d.\n", smallest);

  return 0;
}