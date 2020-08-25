/******************************************* OBJETIVO ******************************************************
 * Faça um programa que preencha um vetor com dez números inteiros aleatórios (de 0 a 100). Calcule e
 * mostre os números superiores a 50 e suas respectivas posições. O programa deverá mostrar uma mensagem
 * caso não exista nenhum número nessa condição.
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
  int random[10], higher_50[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, lst_higher_idx = 0;

  printf("Gerando números aleatórios...\n");
  for(int i = 0; i < 10; i++) {
    // Lógica geral da função rand(): (rand() % (upper - lower + 1)) + lower
    int num = (rand() % 101);
    if (num > 50) {
      higher_50[lst_higher_idx] = num;
      lst_higher_idx++;
    }
    random[i] = num;
  }

  if(lst_higher_idx == 0) {
    printf("Nenhum número gerado é maior que 50.\n");
  } else {
    printf("Os números gerados maiores que 50 são...\n");
    for(int i = 0; i < lst_higher_idx; i++) {
      printf("%d ", higher_50[i]);
    }
    printf("\n");
  }
  return 0;
}