/******************************************* OBJETIVO ******************************************************
 * Um posto está vendendo combustíveis com a seguinte tabela de descontos:
 * a. Álcool:
 *    i. até 20 litros, desconto de 3% por litro
 *    ii. acima de 20 litros, desconto de 5% por litro
 * b. Gasolina:
 *    i. até 20 litros, desconto de 4% por litro
 *    ii. acima de 20 litros, desconto de 6% por litro
 * Escreva um programa que solicita o número de litros vendidos e o tipo de combustível (álcool ou gasolina.
 * Então, calcule e imprima o valor a ser pago pelo cliente sabendo-se que o preço do litro da gasolina é
 * R$ 4,39 e, do álcool, R$ 3,19.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <string.h>

int main(void) {
  char fuel_type;
  char named_fuel[10];
  float liters;
  printf("Digite o tipo de combustível (G para Gasolina ou A para Álcool) e a quantidade de litros desejada (separados por espaço, EX: G 20 -> 20 litros de Gasolina): ");
  scanf("%c %f", &fuel_type, &liters);

  switch(fuel_type) {
    case 'G':
    case 'g':
       strcpy(named_fuel, "Gasolina");
      break;
    case 'A':
    case 'a':
       strcpy(named_fuel, "Álcool");
      break;
    default:
      printf("O valor digitado é inválido, tente novamente...\n");
      return 0;
  }
  printf("Calculando desconto para %s...\n", named_fuel);

  if(strcmp(named_fuel, "Gasolina") == 0) {
    if(liters <= 20) {
      printf("Valor final com desconto de 3%%: %.2f\n", (4.39 * liters) * .97);
    } else {
      printf("Valor final com desconto de 5%%: %.2f\n", (4.39 * liters) * .95);
    }
  } else {
    if(liters <= 20) {
      printf("Valor final com desconto de 4%%: %.2f\n", (3.19 * liters) * .96);
    } else {
      printf("Valor final com desconto de 6%%: %.2f\n", (3.19 * liters) * .94);
    }
  }

  return 0;
}