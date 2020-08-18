/************************************** OBJETIVO **************************************************
 * A seguinte sequência de números 0, 1, 1, 2, 3, 5, 8, 13, 21, ... é conhecida como série de
 * Fibonacci. Nesta sequência, cada número, depois dos 2 primeiros, é igual à soma dos 2
 * anteriores. Escreva um algoritmo que leia um inteiro N (N < 46) e mostre os N primeiros números
 * dessa série.
 * Saída: Os valores devem ser mostrados na mesma linha, separados por um espaço em branco. Não deve
 * haver espaço após o último valor.
 * 
 * EXEMPLO:
 * Entrada: 5
 * 
 * Saída: 0 1 1 2 3
 * 
 * NOTE:
 * Iria user dynamic programming (caching na verdade) para os primeiros 10 números da sequência de
 * Fibonacci, porém em C temos que declarar o tamanho total do array além de lidar com o buffer
 * overflow (duplicando o tamanho do array se este fosse menor do que o desejado). Por conta disso,
 * usei apenas a recursividade.
 * 
 * IMPORTANT:
 * Este código é razoável ate n = 40, mais que isso o call stack pode retornar um erro.
 * 
 * Author: GuhPires
 * Visit: https://github.com/GuhPires/fei-c
 *************************************************************************************************/

#include <stdio.h>

int fib_seq(num){
  if(num == 1) return 0;
  if(num == 2 || num == 3) return 1;
  return fib_seq(num - 1) + fib_seq(num - 2);
}

int main(void) {
  int number, counter = 1;
  printf("Digite o número da sequência de Fibonacci que deseja: ");
  scanf("%d", &number);

  while(counter <= number) {
    printf("%d\t", fib_seq(counter));
    counter++;
  }
  printf("\n");
  return 0;
}