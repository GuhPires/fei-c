/******************************************* OBJETIVO ******************************************************
 * As temperaturas de uma cidade foram armazenadas em um vetor:
 * temperaturas = {-10, -8, 0, 1, 2, 5, -2, -4 }. Faça um programa que imprime a menor e a maior
 * temperatura, assim como a média
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main(void) {
  int temp[] = {-10, -8, 0, 1, 2, 5, -2, -4}, biggest = 0, smallest = 0, avg = 0;

  for(int i = 0; i < 8; i++) {
    if(temp[i] < smallest || i == 0) {
      smallest = temp[i];
    }
    if(temp[i] > biggest || i == 0) {
      biggest = temp[i];
    }
    avg += temp[i];
  }
  avg /= 8;

  printf("A menor temperatura foi de %dºC, a maior de %dºC e a média de %dºC.\n", smallest, biggest, avg);

  return 0;
}