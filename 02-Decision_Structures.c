/******************************************* OBJETIVO ******************************************************
 * A empresa X resolveu conceder um aumento de salários a seus funcionários de acordo com a tabela abaixo: 
 *                      ------------------------------------------------------
 *                      |           Salário         |       Percentual       |
 *                      |---------------------------|------------------------|
 *                      |        0 - 400.00         |           15%          |
 *                      |     400.01 - 800.00       |           12%          |
 *                      |     800.01 - 1200.00      |           10%          |
 *                      |     1200.01 - 2000.00     |           7%           |
 *                      |     Acima de 2000.00      |           4%           |
 *                      ------------------------------------------------------
 * Leia o salário do funcionário e calcule e mostre o novo salário, bem como o valor de reajuste ganho e o
 * índice reajustado, em percentual.
 * 
 * Author: GuhPires
 * Visit: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int main(void) {
  float reajust = 1.0, wage;
  printf("Digite seu salário: ");
  scanf("%f", &wage);

  if(wage <= 400.00) {
    reajust = 1.15;
  } else if(wage <= 800.00) {
    reajust = 1.12;
  } else if(wage <= 1200.00) {
    reajust = 1.07;
  } else {
    reajust = 1.04;
  }
  
  printf("Seu novo salário com o reajuste é de: %.2f\n", wage * reajust);
  return 0;
}