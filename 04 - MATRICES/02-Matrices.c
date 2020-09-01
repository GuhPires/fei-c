/******************************************* OBJETIVO ******************************************************
 * Solicitar dados de uma matriz 4x4 e montar um vetor de 4 elementos com a soma dos elementos ímpares
 * de cada linha
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main(void) {
  int m[4][4], a[4];

  printf("Popule a matriz...\n");
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      printf("Valor: ");
      scanf("%d", &m[i][j]);
      if(m[i][j] % 2 != 0) {
        a[i] += m[i][j];
      }
    }
  }

  printf("Soma dos elementos ímpares de cada linha:\n");
  for(int i = 0; i < 4; i++) {
    printf("Linha %d: %d\n", i + 1, a[i]);
  }

  return 0;
}