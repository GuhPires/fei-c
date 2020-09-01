/******************************************* OBJETIVO ******************************************************
 * Crie uma matriz m[12][12] com números inteiros aleatórios.
 * Em seguida, calcule e mostre a soma ou a média considerando somente aqueles elementos que estão abaixo
 * da diagonal principal da matriz.
 * A entrada do programa deve ser um único caractere maiúsculo 'S' ou 'M', indicando a operação
 * (Soma ou Média) que deverá ser realizada com os elementos da matriz.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int m[12][12], sum, qty;
  char opt;

  // Usando o tempo como Seed pra função rand() 
  srand(time(0));

  printf("Gerando matriz...\n");
  printf("Deseja computar a SOMA [S] ou a MÉDIA [M] dos valores abaixo da diagonal principal? ");
  scanf("%c", &opt);
  if(opt != 'S' && opt != 'M') {
    printf("Opção inválida, tente novamente...\n");
    return 1;
  }
  for(int i = 0; i < 12; i++){
    for(int j = 0; j < 12; j++){
      int num = (rand() % 101);
      m[i][j] = num;
      if(j < i) {
        sum += m[i][j];
        qty++;
      }
    }
  }

  printf("A matriz gerada: \n");
  for(int i = 0; i < 12; i++) {
    printf(" |");
    for(int j = 0; j < 12; j++) {
      printf("\t%d", m[i][j]);
    }
    printf("\t|\n");
  }

  if(opt == 'S') {
    printf("A SOMA dos valores é: %d\n", sum);
  } else {
    printf("A MÉDIA dos valores é: %d\n", sum / qty);
  }

  return 0;
}