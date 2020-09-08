/******************************************* OBJETIVO ******************************************************
 * Crie um programa que contenha um vetor contendo 5 elementos inteiros. Leia esse vetor do teclado e
 * imprima o endereço das posições com conteúdo sendo valores pares
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main(void) {
  int v[5];

  for(int i = 0; i < 5; i++){
    printf("Digite o %dª número: ", i + 1);
    scanf("%d", &v[i]);
  }

  printf("Apresentando os endereções de valores pares...\n");
  for(int i = 0; i < 5; i++){
    if(v[i] % 2 == 0) {
      printf("Endereço do elemento na posição %d: %p\n", i, &v[i]);
    }
  }
  return 0;
}