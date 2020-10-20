/******************************************* OBJETIVO ******************************************************
 * Escreva uma função recursiva para cálculo de potência: pot(base, expoente) que, quando invocada, retorna
 * base^expoente.
 * Por exemplo, pot(3, 4) = 3 * 3 * 3 * 3. Suponha que o expoente seja um número inteiro maior ou igual a 1.
 * Dica: A etapa de recursão pode usar o relacionamento: base^exponente = base * base^exponente – 1
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int pot(int, int);

int main(void) {
  int base = 0, exp = 0;
  printf("Digite um número para a base e outro para o expoente, separados por espaço (EX: 10 2 se quiser 10^2): ");
  scanf("%d %d", &base, &exp);
  printf("%d^%d é %d\n", base, exp, pot(base, exp));
  return 0;
}

int pot(int b, int e) {
  if(e == 0) {
    return 1;
  } else if(e == 1) {
    return b;
  } else if(b == 1) {
    return 1;
  } else if(b == 0) {
    return 0;
  }
  return b * pot(b, e - 1);
}