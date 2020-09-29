/******************************************* OBJETIVO ******************************************************
 * Escreva um programa que leia uma série de strings e imprima apenas aquelas que começam com a letra "b".
 * O programa deve ler strings até que uma linha em branco (nada) seja digitado.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <string.h>

int main(void) {
  char str[100];
  while(1) {
    puts("Digite uma palavra: ");
    gets(str);
    if(!strcmp(str, "")) {
      break;
    }
    if((int) str[0] == 66 || (int) str[0] == 98) {
      printf("Palavra começa com 'b' ou 'B': %s\n", str);
    }
  }

  return 0;
}