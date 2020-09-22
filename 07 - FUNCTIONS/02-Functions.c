/******************************************* OBJETIVO ******************************************************
 * Uma data é considerada mágica quando o dia multiplicado pelo mês é igual ao ano de dois dígitos. Por
 * exemplo, 10 de junho de 1960 é uma data mágica porque junho é o sexto mês e 6 vezes 10 é 60, o que
 * equivale ao ano de dois dígitos. Escreva uma função que determine se uma data é ou não uma data mágica.
 * Use sua função em um programa principal que deve encontrar e exibir todas as datas mágicas do século XX.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdbool.h> 

bool is_magic(int, int, int);

int main(void) {
  int day, month, year;
  printf("Digite sua data de nascimento no formato DD MM AAAA: ");
  scanf("%d %d %d", &day, &month, &year);

  if(is_magic(day, month, year)){
    printf("A data digitada é MÁGICA!\n");
  }
  else {
    printf("A data digitada NÃO é mágica.\n");
  }

  return 0;
}

bool is_magic(int a, int b, int c) {
  int year = c % 100;
  if(a * b == year) {
    return true;
  }
  return false;
}