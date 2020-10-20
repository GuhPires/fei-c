/******************************************* OBJETIVO ******************************************************
 * Usando recursividade, calcule a soma de todos os valores de um vetor de números reais. O vetor pode ter
 * qualquer quantidade de números. Caso base: Tamanho do vetor = 0 => Soma é 0; Passo da recursão: v[n-1]
 * + soma do restante do vetor
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

float array_sum(int, float*);

int main(void) {
  float arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  printf("\nSoma dos elementos do array: %f\n", array_sum(10, arr));
  return 0;
}

float array_sum(int pos, float a[]) {
  if(pos == 0) {
    return a[0];
  }
  return a[pos] + array_sum(pos - 1, a);
}