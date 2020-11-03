/******************************************* OBJETIVO ******************************************************
 * Escreva um arquivo com uma função que receba os comprimentos dos dois lados mais curtos de um triângulo
 * retângulo (catetos) como seus parâmetros. A função deve retornar a hipotenusa do triângulo, calculada
 * usando o teorema de Pitágoras. Escreva também o programa principal que recebe do usuário os comprimentos
 * dos catetos do triângulo retângulo, chama a função para calcular a hipotenusa e exibe o resultado.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include "hypotenuse.h"

int main(void) {
  float c1, c2;
  printf("Digite os catetos (separados por espaço): ");
  scanf("%f %f", &c1, &c2);
  printf("A hipotenusa do triângulo com catetos %f e %f é %f\n", c1, c2, calc_hypotenuse(c1, c2));
  return 0;
}