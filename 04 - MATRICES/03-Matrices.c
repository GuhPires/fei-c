/******************************************* OBJETIVO ******************************************************
 * Faça um programa para receber uma matriz 3×3 (solicitar ao usuário) e apresentar a soma dos elementos da
 * diagonal principal e a matriz na forma como deve ser vista: com linhas e colunas
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main(void) {
  int m[3][3], main_diagonal = 0; 

  printf("Popule a matriz...\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("Valor: ");
      scanf("%d", &m[i][j]);
    }
  }

  printf("A matriz digitada: \n");
  for(int i = 0; i < 3; i++) {
    printf(" |");
    for(int j = 0; j < 3; j++) {
      printf("\t%d", m[i][j]);
      if(i == j) {
        main_diagonal += m[i][j];
      }
    }
    printf("\t|\n");
  }

  printf("A soma da Diagonal Principal é: %d\n", main_diagonal);

  return 0;
}