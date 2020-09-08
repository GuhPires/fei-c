/******************************************* OBJETIVO ******************************************************
 * Crie um programa que deve armazenar uma palavra com 5 letras e apresentá-la, através do uso de ponteiros
 * char. Faça um ponteiro por letra
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main(void) {
  // Vetores são ponteiros.
  char word[5];

  for(int i = 0; i < 5; i++){
    printf("Digite a %dª letra: ", i + 1);
    scanf(" %c", &word[i]);
  }

  printf("\nAs letras da palavra digitada e seus endereços:\n");
  for(int i = 0; i < 5; i++){
    printf("Letra na posição %d: %c\tEndereço: %p\n", i + 1, word[i], &word[i]);
  }
  return 0;
}