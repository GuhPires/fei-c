/******************************************* OBJETIVO ******************************************************
 * Escreva um programa que recebe uma frase e um caractere de pesquisa e determina o total de ocorrências
 * do caractere na frase.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main(void) {
  char str[100], search_c;
  int counter = 0;
  puts("Digite uma frase...");
  fgets(str, 100, stdin);
  puts("Agora digite o caractere que deseja pesquisar...");
  scanf("%c", &search_c);
  printf("Caractere: %c (%d)\n", search_c, search_c);

  puts("Pesquisando...");
  int i = 0;
  while(str[i] != '\0' && str[i] != '\n') {
    if(str[i] == search_c) {
      counter++;
    }
    i++;
  }
  printf("O caractere %c foi encontrado %d vezes\n", search_c, counter);
  return 0;
}