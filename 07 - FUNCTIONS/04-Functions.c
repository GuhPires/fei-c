/******************************************* OBJETIVO ******************************************************
 * Escreva uma função que calcula o quociente e o resto da divisão inteira entre dois números. Utilize
 * apenas as operações de soma e subtração para calcular o resultado. Dica: utilize uma estrutura de
 * repetição para isso. Faça um programa principal que recebe o dividendo e o divisor do usuário e, depois
 * de chamar a função, exibe o quociente e o resto.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

void divide(int, int);

int main(void) {
  int divider, dividend;
  printf("Digite o valor que deseja dividir no formato DIVISOR DIVIDENDO: ");
  scanf("%d %d", &divider, &dividend);
  divide(divider, dividend);

  return 0;
}

void divide(int a, int b) {
  int count = 0, remainder = a;
  while(remainder >= b) {
    remainder -= b;
    count++;
  }
  printf("A divisão de %d por %d é igual a %d com resto %d\n", a, b, count, remainder);
}