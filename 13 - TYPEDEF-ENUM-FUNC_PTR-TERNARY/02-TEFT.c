/******************************************* OBJETIVO ******************************************************
 * Faça uma calculadora com 2 operações básicas, soma e subtração, utilizando operador ternário.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main(void) {
  int n1,n2;
  char op;
  printf("Digite 2 números inteiros (separados por espaço): ");
  scanf("%d %d", &n1, &n2);
  printf("Agora digite 'A' para Adição e 'S' para Subtração: ");
  scanf(" %c", &op);

  int res = op == 'A' ? n1 + n2 : n1 - n2;
  printf("O resultado da operação é %d\n", res);

  return 0;
}