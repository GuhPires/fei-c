/******************************************* OBJETIVO ******************************************************
 * Refaça o programa anterior, só que agora utilize um vetor de char para armazenar sua palavra. Apresente,
 * então, a palavra sem usar estrutura de repetição (você vai precisar fazer aritmética com os ponteiros)
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main(void) {
  char word[5], *pw = word;

  printf("Digite uma palavra de 5 caracteres...\n");
  for(int i = 0; i < 5; i++) {
    printf("Digite a %dª letra: ", i + 1);
    scanf(" %c", &word[i]);
  }

  printf("Palavra: %c %c %c %c %c\n", *pw, *(++pw), *(++pw), *(++pw), *(++pw));

  return 0;
}