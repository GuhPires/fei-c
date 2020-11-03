#include "mtrx.h"
#include <stdio.h>

int bellow_main_diagonal_sum(int mtrx[SIZE][SIZE]) {
  int sum = 0;
  for(int i = 0; i < SIZE; i++) {
    for(int j = 0; j < SIZE; j++) {
      if(j < i) {
        printf("EL: %d\n", mtrx[i][j]);
        sum += mtrx[i][j];
      }
    }
  }
  printf("Sum: %d\n", sum);
  return sum;
}