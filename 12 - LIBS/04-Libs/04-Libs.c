/******************************************* OBJETIVO ******************************************************
 * Crie uma função que receba como parâmetro, uma matriz A=12x12 e retorne a média aritmética dos elementos
 * abaixo da diagonal principal.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include "mtrx.h"

int main(void) {
  int mtrx[SIZE][SIZE] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
    {1, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
    {1, 1, 1, 4, 5, 6, 7, 8, 9, 10, 11, 12},
    {1, 1, 1, 1, 5, 6, 7, 8, 9, 10, 11, 12},
    {1, 1, 1, 1, 1, 6, 7, 8, 9, 10, 11, 12},
    {1, 1, 1, 1, 1, 1, 7, 8, 9, 10, 11, 12},
    {1, 1, 1, 1, 1, 1, 1, 8, 9, 10, 11, 12},
    {1, 1, 1, 1, 1, 1, 1, 1, 9, 10, 11, 12},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 11, 12},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 12},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 12},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  };

  printf("A soma de todos os números abaixo da diagonal principal é %d\n", bellow_main_diagonal_sum(mtrx));
  return 0;
}

  