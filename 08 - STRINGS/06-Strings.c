/******************************************* OBJETIVO ******************************************************
 * Proteção de cheques: Crie um procedimento (função sem retorno) em C que receba uma string (que será
 * utilizada como saída) e um valor float (que representa o valor de um cheque). Este procedimento deverá
 * escrever na string o valor de cheque de forma segura; isto é, contendo asteriscos iniciais antes do
 * valor do cheque.
 * 
 * EXAMPLE: 
 *          char texto[10];
 *          float valor_cheque = 12.35;
 *          valor_seguro(texto, valor_cheque); // texto = “****12.35”
 * 
 * ATENTION: O procedimento deverá assumir que o tamanho da string é de 10 chars (contando com o
 *           terminador)
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <string.h>

void safe_value(char*, float);

int main(void) {
  char text[10] = "";
  float value;
  puts("Digite o valor para o cheque...");
  scanf("%f", &value);
  safe_value(text, value);
  printf("Valor seguro para 12.75: %s\n", text);
  return 0;
}

void safe_value(char *str, float value) {
  char val_c[10];
  sprintf(val_c, "%.2f", value);
  int size = 9 - strlen(val_c);
  for(int i = 0; i < size; i++) {
    str[i] = '*';
  }
  strcat(str, val_c);
}