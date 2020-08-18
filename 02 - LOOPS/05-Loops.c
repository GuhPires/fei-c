/************************************** OBJETIVO **************************************************
 * Escreva um programa que leia um valor inteiro n (1 < n < 1000).
 * n*2 linhas de saída serão apresentadas na execução do programa, seguindo a lógica do exemplo
 * abaixo.
 * 
 * EXEMPLO:
 * Entrada: 5
 * 
 * Saída:
 *        1 1 1
 *        1 2 2
 *        2 4 8
 *        2 5 9
 *        3 9 27
 *        3 10 28
 *        4 16 64
 *        4 17 65
 *        5 25 125
 *        5 26 126
 * 
 * Author: GuhPires
 * Visit: https://github.com/GuhPires/fei-c
 *************************************************************************************************/

#include <stdio.h>
#include <math.h>

int main(void) {
  int counter = 1, line = 0, num;
  printf("Digite um número: ");
  scanf("%d", &num);

  while(counter <= num){
    printf("\t%d\t%d\t%d\n", counter,  (int)pow(counter, 2) + line, (int)pow(counter, 3) + line);
    if(line == 1){
      line = 0;
      counter++;
    } else {
      line++;
    }
  }
  return 0;
}