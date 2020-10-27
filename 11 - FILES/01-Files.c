/******************************************* OBJETIVO ******************************************************
 * Faça um programa que permita que o usuário entre com diversos nomes e telefones para cadastro. Crie,
 * então, um arquivo com essas informações, uma por linha. O usuário finaliza as entradas com ‘0’ para o
 * telefone.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE* file = fopen("phones.txt", "w");
  if(file == NULL) {
    puts("Algo deu errado ao selecionar o arquivo...");
    exit(1);
  }
  unsigned int phone = 1;
  while(phone != 0) {
    printf("Digite um número de telefone ou 0 para sair: ");
    scanf("%d", &phone);
    if(phone != 0) {
      fprintf(file, "%d\n", phone);
    }
  }
  fclose(file);
}