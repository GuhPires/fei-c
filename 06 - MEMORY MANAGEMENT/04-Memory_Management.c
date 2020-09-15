/******************************************* OBJETIVO ******************************************************
 * Escreva um programa em linguagem C que solicita ao usuário a quantidade de alunos de uma turma e aloca
 * dinamicamente um vetor de notas (números reais). Depois de ler as notas, imprime a média aritmética.
 * Obs: não deve ocorrer desperdício de memória; e, após ser utilizada, a memória deve ser liberada
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int students = 0;
  float *grades, sum = 0;

  printf("Digite o número de alunos: ");
  scanf("%d", &students);
  grades = (float*)calloc(students, sizeof(float));

  for(int i = 0; i < students; i++){
    printf("Nota do %dº aluno: ", i+1);
    scanf("%f", &grades[i]);
    sum += grades[i];
  }

  printf("A média aritimética da classe é: %f\n", sum / students);

  free(grades);

  return 0;
}