/******************************************* OBJETIVO ******************************************************
 * Faça um programa que preencha uma matriz 10x3 com as notas de 10 alunos em 3 provas. O programa deverá
 * mostrar um relatório com o número do aluno (número da linha) e a prova em que cada aluno obteve menor
 * nota (número da coluna). O relatório deverá mostrar também quantos alunos tiveram a menor nota em cada
 * uma das provas.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int m[10][3], personal_lowest[10], general_lowest[3], general_lowest_value[3];

  // Usando o tempo como Seed pra função rand() 
  srand(time(0));

  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 3; j++) {
      int num = (rand() % 11);
      m[i][j] = num;
      if(i == 0 || num < general_lowest_value[j]) {
        general_lowest_value[j] = num;
        general_lowest[j] = 1;
      } else if(num == general_lowest_value[j]) {
        general_lowest[j]++;
      }
      if(j == 0 || num < personal_lowest[i]) {
        personal_lowest[i] = num;
      }
    }
  }

  printf("A matriz de notas gerada: \n");
  for(int i = 0; i < 10; i++) {
    printf(" |");
    for(int j = 0; j < 3; j++) {
      printf("\t%d", m[i][j]);
    }
    printf("\t|\n");
  }

  printf("\nMenores notas obtidas: \n");
  for(int i = 0; i < 10; i++) {
    printf("Menor nota do aluno %d: %d\n", i + 1, personal_lowest[i]);
  }

  printf("\nAlunos com as menores notas: \n");
  for(int i = 0; i < 3; i++) {
    printf("Prova %d: %d Aluno(s) com nota %d\n", i + 1, general_lowest[i], general_lowest_value[i]);
  }

  return 0;
}