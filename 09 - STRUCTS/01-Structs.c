/******************************************* OBJETIVO ******************************************************
 * Defina uma struct que irá representar bandas de música. Essa estrutura deve ter o nome da banda, que
 * tipo de música ela toca e o número de integrantes.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

struct band {
  char name[50];
  char genre[100];
  int participants;
};

int main(void) {
  struct band my_band;
  return 0;
}