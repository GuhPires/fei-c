/******************************************* OBJETIVO ******************************************************
 * Considere um jogo de cartas com “baralho tradicional” (cada carta tem seu naipe e seu valor). Implemente
 * o sorteio e distribuição das cartas para 2 jogadores, considerando que cada jogador deve receber 5
 * cartas. Exiba na tela as cartas que cada um dos jogadores recebeu.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card {
  // D -> diamonds; H -> hearts; C -> clubs; S -> spades
  char symbol;
  char value;
};

void print_deck(struct card*);
void distribute_cards(struct card*);

int main(void) {
  // Usando o tempo como Seed pra função rand() 
  srand(time(0));

  // 52 cartas em um baralho
  struct card deck[52];
  char symbols[4] = {'D', 'H', 'C', 'S'};
  // Valor 0 = carta de valor 10 (para não ser lido como uma string ao invés de char)
  char values[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'Q', 'J', 'K'};
  int iter = 0;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 13; j++) {
      deck[iter].symbol = symbols[i];
      deck[iter].value = values[j];
      iter++;
    }
  }

  print_deck(deck);

  distribute_cards(deck);
  return 0;
}

void print_deck(struct card deck[]) {
  printf("\nTodas as cartas do baralho...\n");
  for(int i = 0; i < 52; i++){
    printf("%c de %c\n", deck[i].value, deck[i].symbol);
  }
  printf("-------------------------------\n");
}

void distribute_cards(struct card deck[]) {
  struct card p_one[5];
  struct card p_two[5];

  for(int i = 0; i < 10; i++) {
    // Lógica geral da função rand(): (rand() % (upper - lower + 1)) + lower
    int num = rand() % 53;
    if(i < 5) {
      p_one[i].symbol = deck[num].symbol;
      p_one[i].value = deck[num].value;
    } else {
      p_two[i - 5].symbol = deck[num].symbol;
      p_two[i - 5].value = deck[num].value;
    }
  }

  printf("==== Cartas do Jogador 1 ====\n");
  for(int i = 0; i < 5; i++) {
    printf("%c de %c\n", p_one[i].value, p_one[i].symbol);
  }
  printf("=============================\n");

  printf("==== Cartas do Jogador 2 ====\n");
  for(int i = 0; i < 5; i++) {
    printf("%c de %c\n", p_two[i].value, p_two[i].symbol);
  }
  printf("=============================\n");
}