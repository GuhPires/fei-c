/******************************************* OBJETIVO ******************************************************
 * Escreva um programa em C para encontrar o maior elemento dentro de um vetor de ponteiros arr, usando a
 * Alocação de Memória Dinâmica. O usuário deve digitar a quantidade de elementos do vetor.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int el = 0, *arr, biggest = 0;

  printf("Digite a quantidade de elementos do vetor: ");
  scanf("%d", &el);
  arr = (int*)calloc(el, sizeof(int));

  // Usando o tempo como Seed pra função rand() 
  srand(time(0));
  printf("\nARR = |");
  for(int i = 0; i < el; i++) {
    // Lógica geral da função rand(): (rand() % (upper - lower + 1)) + lower
    int num = (rand() % 101);
    arr[i] = num;
    if(i == 0) {
      printf(" %d", num);
    } else {
      printf("\t%d", num);
    }
  }
  printf(" |\n");

  printf("\nProcurando o maior valor no vetor ARR...\n");
  for(int i = 0; i < el; i++) {
    if(i == 0 || arr[i] > biggest) {
      biggest = arr[i];
    } 
  }

  printf("O maior valor encontrado é: %d\n", biggest);

  free(arr);

  return 0;
}