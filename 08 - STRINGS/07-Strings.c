/******************************************* OBJETIVO ******************************************************
 * Leitor de datas: Crie um procedimento em C que receba uma string data e três inteiros por referência:
 * dia, mes e ano. Este procedimento deverá escrever nas variáveis dia, mes e ano seus respectivos valores
 * obtidos a partir da data representada na string. Considere que a string data possa ter os seguintes
 * formatos: 20/04/2020; 20-04-2020; 20-4-2020; 20.4.2020; 20/4/20
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <string.h>

void date_formatter(char*, int*, int*, int*);

int main(void) {
  char date[11];
  int day, month, year;
  puts("Digite a data...");
  scanf("%s", date);
  date_formatter(date, &day, &month, &year);
  printf("Dia: %d, Mês: %d, Ano: %d\n", day, month, year);
  return 0;
}

void date_formatter(char *date, int *day, int *month, int *year) {
  sscanf(date, "%d%*c%d%*c%d", day, month, year);
}