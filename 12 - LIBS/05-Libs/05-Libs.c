/******************************************* OBJETIVO ******************************************************
 * Crie 3 funções que, juntas, servirão para a criação de placas de veículos no novo padrão do Mercosul.
 * O novo padrão é composto por quatro letras e três números: AAA0A00. Assim, sua primeira função deve
 * gerar e retornar 4 letras aleatoriamente, a segunda função deve gerar e retornar 3 números inteiros
 * aleatoriamente e a terceira função deve juntar e retornar as letras e os números no padrão correto:
 * letra-letra-letra-num-letra-num-num (AAA0A00).
 * Escreva um programa principal que chama as três funções e exibe a placa criada.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include "letters.h"
#include "nums.h"
#include "join.h"

int main(void) {
  char l[4], p[7];
  int n[3];
  rand_letters(l);
  rand_nums(n);
  join_set(l, n, p);
  printf("Placa do Carro: ");
  for(int i = 0; i < 7; i++) {
    printf("%c", p[i]);
  }
  printf("\n");
  return 0;
}