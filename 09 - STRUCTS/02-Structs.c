/******************************************* OBJETIVO ******************************************************
 * Crie um procedimento para preencher 5 estruturas de bandas criadas no exercício anterior. Após criar e
 * preencher, exiba todas as informações das bandas/estruturas. Não se esqueça de usar o operador -> para
 * preencher os membros das structs.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <string.h>

struct band {
  char name[50];
  char genre[100];
  int participants;
};

void fill_band_info(struct band[5], int);
void show_band_info(struct band*);

int main(void) {
  struct band all_bands[5];
  puts("Digite os dados para as bandas...\n");
  for(int i = 0; i < 5; i++) {
    fill_band_info(&all_bands[i], i);
  }
  puts("Mostrando todas as bandas cadastradas...\n");
  show_band_info(all_bands);
  return 0;
}

void fill_band_info(struct band *b, int idx) {
  printf("Digite o nome da %dª banda: ", idx + 1);
  scanf("%s", b->name);
  printf("Digite o gênero da %dª banda: ", idx + 1);
  scanf("%s", b->genre);
  printf("Agora o número de participantes da %dª banda: ", idx + 1);
  scanf("%d", &b->participants);
  printf("\n");
}

void show_band_info(struct band b[5]) {
  for(int i = 0; i < 5; i++) {
    printf("Banda %s\n", b[i].name);
    printf("Gênero %s\n", b[i].genre);
    printf("Com %d participantes\n", b[i].participants);
    printf("\n");
  }
}

