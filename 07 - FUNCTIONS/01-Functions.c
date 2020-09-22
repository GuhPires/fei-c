/******************************************* OBJETIVO ******************************************************
 * Implemente uma função float potencia(float x, int n) que devolva o valor de x^n
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <math.h>

float potencia(float, int);

int main(void) {
  printf("Resultado: %f\n", potencia(2, 4));
  return 0;
}

float potencia(float x, int n) {
  return pow(x,n);
}