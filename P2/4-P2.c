/******************************************* OBJETIVO ******************************************************
 * Os alunos de uma escola têm 5 avaliações com nota no decorrer do ano. As notas das 5 avaliações são
 * exportadas pelo sistema da escola em um arquivo: notas.txt (clique com o botão direito em cima do link
 * notas.txt e em "Salvar link como..." para baixar o arquivo). O arquivo contém, em cada linha, o nome do
 * aluno e as suas 5 notas na sequência.
 * 
 * Você deve, então, fazer um programa para ler as informações do arquivo, calcular a média aritmética de
 * cada aluno, e dizer quais foram os alunos reprovados, considerando que a nota de corte para aprovação é
 * 5.0 (portanto, reprovados são os alunos com média < 5.0).
 * 
 * Então, você deve gerar um relatório, que deve ser impresso no terminal, no seguinte formato (deve ser
 * completo - com todos os alunos e as informações faltantes)
 * 
 * EXAMPLE:
 *          Medias Finais
 *        ----------------
 *        Nome       Media
 *        Cesar      8.00
 *        Jonas      4.80
 *        Vagner     5.00
 *
 *        ----------------
 *        Alunos reprovados:
 *        Jonas
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avg.h"

int main(void) {
  int grades[5][20];
  char name[200], reproved[20][200];

  FILE* file = fopen("notas.txt", "r");
  if(file == NULL) {
    puts("Algo deu errado ao abrir o arquivo...");  
    exit(1);
  }

  printf("Médias Finais\n");
  printf("----------------------------------\n");
  printf("Nome \t\t Média\n");

  int line = 0;
  int rep = 0;
  while(!feof(file)) {
    fscanf(file, "%s %d %d %d %d %d", name, &grades[0][line], &grades[1][line], &grades[2][line], &grades[3][line], &grades[4][line]);

    int personal_grades[5] = {grades[0][line], grades[1][line], grades[2][line], grades[3][line], grades[4][line]};
    float final_grade = calc_avg(personal_grades, 5);
    printf("%s \t\t %f\n", name, final_grade);

    if(final_grade < 5.0) {
      strcpy(reproved[rep], name);
      rep++;
    }
    line++;
  }
  printf("----------------------------------\n");
  printf("Alunos reprovados:\n");
  for(int j = 0; j < rep; j++) {
    printf("%s\n", reproved[j]);
  }
  return 0;
}