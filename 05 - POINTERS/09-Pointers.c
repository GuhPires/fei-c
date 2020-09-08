/******************************************* OBJETIVO ******************************************************
 * Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas. Imprima o endereço de
 * cada posição dessa matriz
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main(void) {
  float m[3][3];

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      printf("Endereço da posição %d %d: %p\n", i + 1, j + 1, &m[i][j]);
    }
  }
  return 0;
}