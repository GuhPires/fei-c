/******************************************* OBJETIVO ******************************************************
 * Crie um programa que lê 4 pontos (struct ponto) num plano cartesiano, e os armazena na estrutura
 * retângulo (struct retangulo). Exiba, então, a área e o perímetro do retângulo.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <math.h>

struct point {
  int x;
  int y;
};

struct rectangle {
  struct point points[4];
};

float calc_perimeter(struct rectangle);
float calc_area(struct rectangle);

int main(void) {
  struct rectangle rect;
  int coordinates[4][2] = { {0, 0}, {0, 4}, {6, 4}, {6, 0} };
  for(int i = 0; i < 4; i++) {
    rect.points[i].x = coordinates[i][0];
    rect.points[i].y = coordinates[i][1];
  }
  printf("O tamanho do perímetro é %f\n", calc_perimeter(rect));
  printf("O tamanho da área é %f\n", calc_area(rect));
  return 0;
}

float calc_perimeter(struct rectangle r) {
  float height = sqrt(pow((r.points[1].x - r.points[0].x), 2) + pow((r.points[1].y - r.points[0].y), 2));
  float width = sqrt(pow((r.points[3].x - r.points[0].x), 2) + pow((r.points[3].y - r.points[0].y), 2));
  return (height * 2) + (width * 2);
}

float calc_area(struct rectangle r) {
  float height = sqrt(pow((r.points[1].x - r.points[0].x), 2) + pow((r.points[1].y - r.points[0].y), 2));
  float width = sqrt(pow((r.points[3].x - r.points[0].x), 2) + pow((r.points[3].y - r.points[0].y), 2));
  return height * width;
}