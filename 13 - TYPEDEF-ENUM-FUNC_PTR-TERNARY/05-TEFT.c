/******************************************* OBJETIVO ******************************************************
 * Faça um programa que tenha uma struct aluno com nome, número de matrícula e curso. Receba do usuário a
 * informação de 5 alunos, armazene em um vetor dessa estrutura e imprima os dados na tela. Utilize typedef
 * para fazer a struct.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

typedef struct {
  char name[50];
  int number;
  char course[100];
} student;

int main(void) {
  student students[5];
  puts("Iniciando o cadastro dos alunos...");
  for(int i = 0; i < 5; i++) {
    printf("Nome do %dº aluno: ", i + 1);
    scanf("%s", students[i].name);
    printf("Matrícula do %dº aluno: ", i + 1);
    scanf("%d", &students[i].number);
    printf("Curso do %dº aluno: ", i + 1);
    scanf("%s", students[i].course);
    printf("\n");
  }

  puts("Alunos cadastrados:");
  for(int i = 0; i < 5; i++) {
    puts("============================");
    printf("Nome: \t\t%s\n", students[i].name);
    printf("Matrícula: \t%d\n", students[i].number);
    printf("Curso: \t\t%s\n", students[i].course);
    puts("============================");
  }
  return 0;
}