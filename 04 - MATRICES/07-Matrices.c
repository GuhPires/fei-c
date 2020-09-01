/******************************************* OBJETIVO ******************************************************
 * Na teoria dos sistemas, define-se o elemento MINIMAX de uma matriz como sendo o maior elemento da linha
 * onde se encontra o menor elemento da matriz. Elabore um programa que carregue uma matriz 4x7 com números
 * reais, calcule e mostre seu MINIMAX e sua posição (linha e coluna).
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int m[4][7], coord_line, coord_row, lowest, biggest;

  // Usando o tempo como Seed pra função rand() 
  srand(time(0));

  printf("Gerando matriz...\n");
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 7; j++) {
      int num = (rand() % 101);
      m[i][j] = num;
      if((j == 0 && i == 0)|| num < lowest) {
        lowest = num;
        coord_line = i;
        coord_row = j;
      }
    }
  }

  printf("\nA matriz gerada: \n");
  for(int i = 0; i < 4; i++) {
    printf(" |");
    for(int j = 0; j < 7; j++) {
      printf("\t%d", m[i][j]);
    }
    printf("\t|\n");
  }

  printf("\nMenor número da matriz é %d, que está no endereço [%d][%d]\n", lowest, coord_line, coord_row);

  for(int i = 0; i < 7; i++) {
    if(i == 0 || m[coord_line][i] > biggest) {
      biggest = m[coord_line][i];
      coord_row = i;
    }
  }

  printf("\nMINMAX é %d, no endereço [%d][%d]\n", biggest, coord_line, coord_row);

  return 0;
}