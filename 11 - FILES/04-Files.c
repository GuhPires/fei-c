/******************************************* OBJETIVO ******************************************************
 * Escreva uma função que leia uma sequência numérica do arquivo numeros3.txt em um vetor. Além de ler o
 * conteúdo do arquivo, a função deve eliminar os números repetidos e gravar, somente os números únicos,
 * em outro arquivo numeros3unicos.txt
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// FUNCTIONS
void clean(FILE*, int[], int);

// GLOBAL VARIABLES
int lst_pos = 0;

int main(void) {
  FILE* nums = fopen("numeros3.txt", "r");
  FILE* nums_unique = fopen("numeros3unicos.txt", "w");
  int cleaned[1000];
  if(nums == NULL || nums_unique == NULL) {
    puts("Ocorreu algo de errado com um dos arquivos...");
    exit(1);
  }

  int num = 0;
  while(!feof(nums)) {
    fscanf(nums, "%d", &num);
    clean(nums_unique, cleaned, num);
  }

  puts("Arquivo \"numeros3.txt\" filtrado e salvo em \"numeros3unicos.txt\"");
  return 0;
}

void clean(FILE* f, int a[], int num) {
  int should_write = 1;
  for(int i = 0; i < lst_pos; i++) {
    if(num == a[i]) {
      should_write = 0;
      break;
    }
  }
  if(should_write) {
    a[lst_pos] = num;
    fprintf(f, "%d\n", num);
    lst_pos++;
  }
}