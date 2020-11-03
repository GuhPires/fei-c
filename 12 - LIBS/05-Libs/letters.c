#include "letters.h"

void rand_letters(char *l ) {
  // Usando o tempo como Seed pra função rand() 
  srand(time(0));
  char letters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
  for(int i = 0; i < 4; i++) {
    // Lógica geral da função rand(): (rand() % (upper - lower + 1)) + lower
    int rand_idx = (rand() % 26);
    l[i] = letters[rand_idx];
  }
  for(int i = 0; i < 4; i++) {
    printf("\t%c", l[i]);
  }
  printf("\n");
}