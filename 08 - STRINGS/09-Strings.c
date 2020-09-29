/******************************************* OBJETIVO ******************************************************
 * Escreva um programa que gere números aleatórios para criar frases. O programa deve usar quatro arrays
 * de ponteiros para char, chamados de artigo, substantivo, verbo e preposição. O programa deve criar uma
 * frase selecionando uma palavra aleatória de cada array na seguinte ordem: artigo, substantivo, verbo,
 * preposição, artigo e substantivo. Conforme cada palavra é escolhida, ela deve ser concatenada às
 * palavras anteriores em um array grande o suficiente para conter a frase inteira. As palavras devem ser
 * separadas por espaços.
 * 
 * O programa deve gerar 20 frases. O array artigo deve conter os artigos "o", "a", "um", "algum" e
 * "qualquer"; o array de substantivo deve conter os substantivos "menino", "menina", "cachorro", "cidade"
 * e "carro"; o array de verbos deve conter os verbos "dirigiu", "saltou", "correu", "caminhou" e "pulou";
 * o array de preposição deve conter as preposições "para", "de", "sobre", "sob" e "ligado".
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char artigos[5][10] = {"o", "a", "um", "algum", "qualquer"};
char subs[5][10] = {"menino", "menina", "cachorro", "cidade", "carro"};
char verbos[5][10] = {"dirigiu", "saltou", "correu", "caminhou", "pulou"};
char preps[5][10] = {"para", "de", "sobre", "sob", "ligado"};

char* choose_verbal(int, int);

int main(void) {
  // Usando o tempo como Seed pra função rand()
  srand(time(0));

  for(int count = 0; count < 20; count++) {
    char frase[100] = {};
    for(int i = 0; i < 6; i++) {
      // Lógica geral da função rand(): (rand() % (upper - lower + 1)) + lower
      int rand_num = (rand() % 5);
      strcat(frase, choose_verbal(i, rand_num));
      if(i < 5) {
        strcat(frase, " ");
      }
      // ---------------- DEBUG -----------------
      // printf("Palavra: %s\n", choose_verbal(i, rand_num));
      // printf("Frase: %s\n", frase);
      // printf("--------------------------\n");
      // printf("Artigo: %s\n", artigos[i]);
      // printf("Substantivo: %s\n", subs[i]);
      // printf("Verbos: %s\n", verbos[i]);
      // printf("Preposições: %s\n", preps[i]);
      // printf("--------------------------\n");
      // ---------------- END -----------------
    }
    printf("Frase gerada: %s\n", frase);
    printf("------------------------\n");
  }
  return 0;
}

char* choose_verbal(int idx, int rand) {
  switch(idx) {
    case 0:
    case 4:
    return artigos[rand];
      break;
    case 1:
    case 5:
    return subs[rand];
      break;
    case 2:
    return verbos[rand];
      break;
    case 3:
    return preps[rand];
      break;
  }
  return "";
}