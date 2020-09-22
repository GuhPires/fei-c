/******************************************* OBJETIVO ******************************************************
 * Crie uma função void modifica (int *x), que deve mudar o valor passado como parâmetro para o próximo
 * inteiro ímpar. Ex: para a variável inteira a, a=5; modifica(&a); fará com que o valor de a se torne 7;
 * a=2; modifica(&a); fará com que o valor de a se torne 3
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

void modifica(int*);

int main(void) {
  int num = 6;
  modifica(&num);

  printf("Próximo inteiro: %d\n", num);

  return 0;
}

void modifica(int *x) {
  if(*x % 2 != 0) {
    *x += 2;
  } else {
    (*x)++;
  }
}