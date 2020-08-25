/******************************************* OBJETIVO ******************************************************
 * Desafio: Faça um programa que preencha um vetor com vinte números inteiros aleatórios (de 0 a 200).
 * Ordene, então, o vetor de forma crescente
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  // Usando o tempo como Seed pra função rand() 
  srand(time(0));
  int random[20];

  for(int i = 0; i < 20; i++) {
    // Lógica geral da função rand(): (rand() % (upper - lower + 1)) + lower
    int num = (rand() % 201);
    random[i] = num;
  }

  // "Dumb ordering" O(n^2)
  for(int i = 0; i < 20; i++) {
    for(int j = 0; j < 20; j++) {
      if(random[i] < random[j]) {
        int temp = random[i];
        random[i] = random[j];
        random[j] = temp;
      }
    }
  }

  printf("Os valores gerados em ordem crescente...\n");

  for(int i = 0; i < 20; i++) {
    printf("%d ", random[i]);
  }
  printf("\n");

  return 0;
}
 