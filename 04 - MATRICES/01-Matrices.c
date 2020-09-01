/******************************************* OBJETIVO ******************************************************
 * Faça um programa que cria uma matriz m 10 x 15, sendo que cada elemento é um inteiro gerado
 * aleatoriamente. Então, exiba a matriz completa e, na sequência, somente os elementos da primeira
 * coluna da matriz.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int m[10][15];

  // Usando o tempo como Seed pra função rand() 
  srand(time(0));

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 15; j++){
      int num = (rand() % 101);
      m[i][j] = num;
    }
  }

  printf("A matriz gerada: \n");
  for(int i = 0; i < 10; i++) {
    printf(" | ");
    for(int j = 0; j < 15; j++) {
      printf(" %d ", m[i][j]);
    }
    printf("\n");
  }
  
  printf("\nApenas a primeira coluna:\n");
  for(int i = 0; i < 1; i++){
    printf(" | ");
    for(int j = 0; j < 15; j++){
      printf(" %d ", m[i][j]);
    }
    printf(" | \n");
  }

  return 0;
}