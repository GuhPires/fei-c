/******************************************* OBJETIVO ******************************************************
 * Crie um programa que inverta a ordem das linhas do arquivo pares.txt. A primeira linha deve conter o
 * maior número e a última linha o menor. Salve o resultado em outro arquivo, chamado pares_invertido.txt.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE* even = fopen("pares.txt", "r");
  FILE* even_inverted = fopen("pares_invertidos.txt", "w");
  int nums[500];
  if(even == NULL || even_inverted == NULL) {
    puts("Ocorreu algo de errado com um dos arquivos...");
    exit(1);
  }

  int i = 0;
  while(!feof(even)){
    fscanf(even, "%d", &nums[i]);
    i++;
  }
  puts("Arquivo \"pares.txt\" lido!");

  for(int j = 499; j > -1; j--){
    fprintf(even_inverted, "%d\n", nums[j]);
  }
  puts("Arquivo \"pares_invertido.txt\" preenchido!");
  fclose(even);
  fclose(even_inverted);
  return 0;
}