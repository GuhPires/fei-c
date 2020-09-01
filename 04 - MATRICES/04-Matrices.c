/******************************************* OBJETIVO ******************************************************
 * Faça um programa que cria uma matriz A 10x5 com números inteiros aleatórios e, então, exiba a matriz
 * transposta de A ( At ). Determinar a transposta de uma matriz é reescrevê-la de forma que suas linhas e
 * colunas troquem de posições ordenadamente, isto é, a primeira linha é reescrita como a primeira coluna,
 * a segunda linha é reescrita como a segunda coluna e assim por diante, até que se termine de reescrever
 * todas as linhas na forma de coluna.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int A[10][5], tA[5][10];

  // Usando o tempo como Seed pra função rand() 
  srand(time(0));

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 5; j++){
      int num = (rand() % 101);
      A[i][j] = num;
      tA[j][i] = num;
    }
  }

  printf("A matriz gerada: \n");
  for(int i = 0; i < 10; i++) {
    printf(" | ");
    for(int j = 0; j < 5; j++) {
      printf(" %d ", A[i][j]);
    }
    printf("\n");
  }

  printf("\nA transposta da matriz gerada: \n");
  for(int i = 0; i < 5; i++) {
    printf(" | ");
    for(int j = 0; j < 10; j++) {
      printf(" %d ", tA[i][j]);
    }
    printf("\n");
  }

  return 0;
}