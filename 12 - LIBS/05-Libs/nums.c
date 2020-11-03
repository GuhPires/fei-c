#include "nums.h"

void rand_nums(int *n) {
  // Usando o tempo como Seed pra função rand() 
  srand(time(0));
  for(int i = 0; i < 3; i++) {
    // Lógica geral da função rand(): (rand() % (upper - lower + 1)) + lower
    n[i] = (rand() % 11);
  }
  for(int i = 0; i < 3; i++) {
    printf("\t%d", n[i]);
  }
  printf("\n");
}