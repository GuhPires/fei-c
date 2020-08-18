/************************************** OBJETIVO **************************************************
 * Faça um programa que receba um número inteiro maior que 1 e verifique se o número fornecido é
 * primo ou não. Mostre uma mensagem de número primo ou de número não primo. Um número é primo
 * quando é divisível apenas pelo número um e por ele mesmo.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 *************************************************************************************************/

#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int number;
  bool is_prime = true;

  printf("Digite um número inteiro: ");
  scanf("%d", &number);
  for(int i = 1; i <= number; i++) {
    if(i != number && i != 1 && number % i == 0) {
      printf("O número %d não é primo.\n", number);
      is_prime = false;
      break;
    }
  }

  if(is_prime) printf("O número %d é primo.\n", number);

  return 0;
}