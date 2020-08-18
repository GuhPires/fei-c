/************************************** OBJETIVO **************************************************
 * Escreva um programa que leia números digitados pelo usuário. O programa deve ler os números até
 * que 0 (zero) seja digitado. Quando 0 for digitado, o programa deve exibir a quantidade de dígitos
 * que foram digitados, a somatória destes dígitos e a média aritmética.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 *************************************************************************************************/

#include <stdio.h>

int main(void) {
  int counter = 0;
  float digit;
  float digits_sum = 0;
  while(digit){
    printf("Digite um número: ");
    scanf("%f", &digit);
    digits_sum += digit;
    if(digit) counter++;
  }

  printf("Foram digitados %d números\n", counter);
  printf("A soma desses números é %.2f\n", digits_sum);
  printf("A média aritimética é %.2f\n", digits_sum / counter);

  return 0;
}