/************************************** OBJETIVO **************************************************
 * Um zoológico em particular determina o preço da entrada com base na idade do visitante. Os
 * visitantes com 2 anos de idade ou menos têm entrada gratuita. Crianças entre 3 e 12 anos pagam
 * R$ 14,00. Idosos com 65 anos ou mais pagam R$ 18,00. A entrada para todos os outros visitantes
 * custa R$ 23,00.
 * Crie um programa que comece lendo as idades de todos os visitantes de um mesmo grupo, sendo uma
 * idade informada em cada linha. O usuário digitará 0 (zero) para indicar que não há mais pessoas
 * no grupo. Em seguida, seu programa deve exibir o custo total para o grupo. O custo deve ser exibido
 * usando duas casas decimais.
 * 
 * Author: GuhPires
 * Visit: https://github.com/GuhPires/fei-c
 *************************************************************************************************/

#include <stdio.h>

int main(void) {
  int age;
  float total_price = 0;
  do {
    float price;
    printf("Digite a idade do visitante: ");
    scanf("%d", &age);

    if(age <= 2) {
      printf("Caso 1\n");
      price = 0;
    } else if(age >= 3 && age <= 12) {
      printf("Caso 2\n");
      price = 14;
    } else if(age >= 63) {
      printf("Caso 3\n");
      price = 18;
    } else {
      printf("Caso 4\n");
      price = 23;
    }

    total_price += price;

  } while(age);

  printf("O preço total é R$%.2f\n", total_price);
  
  return 0;
}