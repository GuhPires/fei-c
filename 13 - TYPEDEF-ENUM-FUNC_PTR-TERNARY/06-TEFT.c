/******************************************* OBJETIVO ******************************************************
 * Crie um procedimento chamado iterate que recebe um vetor de int, o número de elementos e um ponteiro
 * para um procedimento que somará 1 em cada um dos números do vetor.
 * 
 * EXAMPLE:
 *          ... add1(...){ .............
 *          }
 *          int main(){
 *            int i[]={1,2,3,4,5};
 *            iterate(i,5, add1);
 * 
 *            //No final, o vetor i deverá ser {2,3,4,5,6}
 *          }
 * 
 * OBS: Sintaxe - vetores de ponteiros de funções: tipo_retorno (* nome_ponteiro[x])(tipos param.)
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

void iter(int*, int, int (int));
int add1(int);

int main(void) {
  int a[5] = {10, 20, 30, 40, 50};
  iter(a, 5, add1);
  return 0;
}

void iter(int *arr, int pos, int (*cb)(int)) {
  for(int i = 0; i < pos; i++) {
    printf("Valor ANTES da soma: %d\n", arr[i]);
    arr[i] = cb(arr[i]);
    printf("Valor DEPOIS da soma: %d\n", arr[i]);
    printf("\n");
  }
}

int add1(int el) {
  return ++el;
}