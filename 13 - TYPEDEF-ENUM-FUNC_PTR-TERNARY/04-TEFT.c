/******************************************* OBJETIVO ******************************************************
 * Escreva um programa em C que leia as medidas dos lados de um triângulo e escreva se ele é equilátero,
 * isósceles ou escaleno. Utilize enum para os tipos dos triângulos.
 * • Triângulo equilátero: 3 lados iguais.
 * • Triângulo isósceles: 2 lados iguais.
 * • Triângulo escaleno: 3 lados diferentes.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

enum triangle_type { equi = 1, isoc, esca };

int classify_triangle(float, float, float);

int main(void) {
  float s1, s2, s3;
  printf("Digite o tamanho dos lados do triângulo (separados por espaço): ");
  scanf("%f %f %f", &s1, &s2, &s3);
  int type = classify_triangle(s1, s2, s3);
  if(type) {
    switch (type) {
      case 1:
        printf("O triângulo digitado é EQUILÁTERO\n");
      break;
      case 2:
        printf("O triângulo digitado é ISÓCELES\n");
      break;
      case 3:
        printf("O triângulo digitado é ESCALENO\n");
      break;
    }
  }
  return 0;
}

int classify_triangle(float a, float b, float c) {
  if(a == b && a == c) return 1;
  else if(a == b && a != c) return 2;
  else if(a != b && b != c) return 3;
  return 0;
}