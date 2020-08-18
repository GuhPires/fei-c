/******************************************* OBJETIVO ******************************************************
 * Faça um programa que calcule as raízes de uma equação do segundo grau, na forma ax2 + bx + c. O programa
 * deverá pedir os valores de a, b e c e fazer as consistências, informando ao usuário as seguintes
 * situações: 
 * a. Se o usuário informar o valor de a igual a zero, a equação não é do segundo grau e o programa não
 * deve pedir os demais valores, sendo encerrado;
 * b. Se o delta calculado for negativo, a equação não possui raízes reais. Informe ao usuário e encerre o
 * programa;
 * c. Se o delta calculado for igual a zero a equação possui apenas uma raiz real; informe-a ao usuário;
 * d. Se o delta for positivo, a equação possui duas raiz reais; informe-as ao usuário;
 * 
 * Author: GuhPires
 * Visit: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <math.h>

float calc_delta(float a, float b, float c) {
  return (b * b) - (4 * a * c);
}

int main(void) {
  float a, b, c;
  printf("Digite os valores de 'a', 'b' e 'c' (respectivamente) separados por um espaço (EX: 10 7 6)\n");
  printf("OBS: Preencha com 0 se não houver um número (EX: 10 0 2 -> 'b' inexistente)\n");
  scanf("%f %f %f", &a, &b, &c);

  if(!a) {
    printf("Parece que a equação não é de 2º grau, pois não existe 'a'...\n");
    return 0;
  }

  float delta = calc_delta(a, b, c);
  if(delta < 0) {
    printf("𝞓 negativo (%.4f), portanto não existem raízes reais.\n", delta);
  } else if(delta == 0) {
    printf("𝞓 igual a 0 (%.4f), existe apenas uma raíz real: %.4f.\n", delta, ((-b) + sqrtf(delta)) / (2 * a));
  } else {
    printf("𝞓 positivo (%.4f), existem duas raízes reais: %.4f e %.4f.\n", delta, ((-b) + sqrtf(delta)) / (2 * a), ((-b) - sqrtf(delta)) / (2 * a));
  }

  return 0;
}