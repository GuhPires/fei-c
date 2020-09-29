/******************************************* OBJETIVO ******************************************************
 * Escreva um programa baseado no Exercício 5 que recebe uma frase e determina as ocorrências totais de
 * cada letra do alfabeto. Letras maiúsculas e minúsculas devem ser contadas juntas. Armazene os totais
 * para cada letra em um array e imprima os valores em formato tabular depois que os totais forem
 * determinados.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

char* strlower(char*);

int main(void) {
  char str[100];
  int alpha_counter[26];

  puts("Digite uma frase...");
  fgets(str, 100, stdin);
  char *lwr_str = strlower(str);

  for(int i = 97; i < 123; i++) {
    alpha_counter[i - 97] = 0;
    int j = 0;
    while(lwr_str[j] != '\0' && lwr_str[j] != '\n') {
      if((int) lwr_str[j] == i) {
        alpha_counter[i - 97]++;
      }
      j++;
    }
  }

  for(int i = 0; i < 26; i++){
    printf("Letra %c:\t%d\n", (char) (i + 97), alpha_counter[i]);
  }

  return 0;
}

char* strlower(char *str) {
  int i = 0;
  while(str[i] != '\0') {
    if((int) str[i] > 64 && (int) str[i] < 91) {
      str[i] += 32;
    }
    i++;
  }
  return str;
}