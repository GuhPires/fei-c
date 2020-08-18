/************************************** OBJETIVO **************************************************
 * Leia 2 valores reais (x e y), que devem representar as coordenadas de um ponto em um plano. Então, 
 * determine a que quadrante (Q1, Q2, Q3 ou Q4) o ponto pertence ou se está sobre um dos eixos cartesianos 
 * ou na origem (x = y = 0).
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 *************************************************************************************************/

#include <stdio.h>

char define_quadrant(float x_coord, float y_coord) {
  char q;
  if (x_coord > 0 && y_coord > 0) {
    q = '1';
  } else if (x_coord < 0 && y_coord > 0) {
    q = '2';
  } else if (x_coord < 0 && y_coord < 0) {
    q = '3';
  } else {
    q = '4';
  }
  return q;
}

int main(void) {
  printf("Digite dois números reais de coordenadas X e Y respectivamente (separados por espaço, EX: 10 1): ");
  float x, y;
  scanf("%f %f", &x, &y);
  if (x == 0) {
    printf("Ponto se encontra sobre o eixo X: (%.2f, %.2f)\n", x, y);
  } else if (y == 0) {
    printf("Ponto se encontra sobre o eixo Y: (%.2f, %.2f)\n", x, y);
  } else {
    printf("O ponto (%.2f, %.2f) está no Quadrante %c\n", x, y, define_quadrant(x, y));
  }
  return 0;
}