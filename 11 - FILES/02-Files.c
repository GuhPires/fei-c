/******************************************* OBJETIVO ******************************************************
 * Faça um programa que cria e grava números pares e ímpares em arquivos separados. Números de 0 a 999.
 * Números pares no arquivo pares.txt e os ímpares no arquivo impares.txt
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE* even = fopen("pares.txt", "w");
  FILE* odd = fopen("impares.txt", "w");
  for(int i = 0; i < 1000; i++) {
    if(i % 2 == 0) {
      fprintf(even, "%d\n", i);
    } else {
      fprintf(odd, "%d\n", i);
    }
  }
  fclose(even);
  fclose(odd);
  return 0;
}