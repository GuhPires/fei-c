/******************************************* OBJETIVO ******************************************************
 * Receba pelo teclado a quantidade q de caracteres de uma palavra. Crie, então, um vetor de ponteiro char
 * com alocação dinâmica (de tamanho q). Utilizando uma estrutura de repetição receba um caractere por
 * iteração e inclua no vetor. Imprima então a frase recebida utilizando o especificador “%s”
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int char_num = 0;
  char *c;

  printf("Digite a quantidade de caracteres que deseja digitar: ");
  scanf("%d", &char_num);
  c = (char*)malloc(char_num * sizeof(char));
  if(c == NULL) {
    printf("Memória não alocada!");
    return 0;
  }

  for(int i = 0; i < char_num; i++) {
    printf("Digite o %dº caractere: ", i+1);
    scanf(" %c", &c[i]);
  }

  printf("Os caracteres digitados formam a palavra: %s\n", c);

  free(c);

  return 0;
}