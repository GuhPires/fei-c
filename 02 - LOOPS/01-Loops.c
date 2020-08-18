/************************************** OBJETIVO **************************************************
 * Escreva um programa que calcula a média aritmética de 5 números digitados pelo usuário. Utilize
 * contadores e acumuladores.
 * 
 * considerando que o primeiro número digitado é n1, segundo n2, ...
 * media = (n1+n2+n3+n4+n5) / 5
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 *************************************************************************************************/

#include <stdio.h>

int main(void) {
  int counter = 1;
  float grades;
  do {
    float grade;
    printf("Digite uma nota: ");
    scanf("%f", &grade);
    grades += grade;
    counter++;
  } while(counter <= 5);

  printf("A média final é: %.2f", grades / 5);

  return 0;
}