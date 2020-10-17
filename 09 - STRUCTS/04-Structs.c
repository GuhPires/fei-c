/******************************************* OBJETIVO ******************************************************
 * Crie um programa que lê 4 pontos (struct ponto) num plano cartesiano, e os armazena na estrutura
 * retângulo (struct retangulo). Exiba, então, a área e o perímetro do retângulo.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

struct ponto {
  int x;
  int y;
};

struct rectangle {
  struct ponto p1;
  struct ponto p2;
  struct ponto p3;
  struct ponto p4;
};

float calc_perimeter(struct rectangle);
float calc_area(struct rectangle);

int main(void) {
  struct rectangle rect;

  return 0;
}

float calc_perimeter(struct rectangle r) {
  return ;
}

float calc_area(struct rectangle r) {
  return ;
}