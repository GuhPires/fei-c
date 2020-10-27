/******************************************* OBJETIVO ******************************************************
 * Faça um programa que receba do usuário o nome de um arquivo texto e mostre na tela quantas letras são
 * vogais e quantas são consoantes dentro do arquivo. Você pode utilizar qualquer arquivo para testar.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char file_name[100];
  int vowels = 0, consonants = 0;
  printf("Digite o nome do arquivo (COM A EXTENSÃO) que deseja ler (o nome NÃO pode conter espaços): ");
  scanf("%s", file_name);
  FILE* file = fopen(file_name, "r");
  if(file == NULL) {
    puts("Não foi possível abrir o arquivo digitado...");
    exit(1);
  }

  while(!feof(file)) {
    int c = (int)fgetc(file);
    if((c >= 65 && c <= 90)|| (c >= 97 && c <= 122)) {
      switch(c) {
        case 65:
        case 69:
        case 73:
        case 79:
        case 85:
        case 97:
        case 101:
        case 105:
        case 111:
        case 117:
          vowels++;
        break;
        default:
          consonants++;
        break;
      }
    }
  }

  printf("Existem %d vogais e %d consoantes no arquivo \"%s\"\n", vowels, consonants, file_name);
  return 0;
}