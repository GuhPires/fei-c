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
bool is_leap_year(int);

int main(void) {
  for(int i = 1900; i < 2000; i++) {
    bool leap = is_leap_year(i);
    for(int j = 1; j < 13; j++) {
      for(int k = 1; k < 32; k++) {
        if((leap && j == 2 && k == 30) || (!leap && j == 2 && k == 29) || (j == 4 && k == 31) || (j == 6 && k == 31) || (j == 9 && k == 31) || (j == 11 && k == 31)) {
          break;
        }
        if(is_magic(k, j, i)){
          printf("A data %d/%d/%d é MÁGICA!\n", k, j, i);
        }
      }
    }
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

bool is_leap_year(int a) {
  if(a % 4 == 0) {
    if(a % 100 != 0) {
      // printf("%d é bissexto\n\n", a);
      return true;
    }
  } else if(a % 400 == 0) {
    // printf("%d é bissexto\n\n", a);
    return true;
  }
  return false;
}