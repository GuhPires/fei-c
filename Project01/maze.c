/******************************************* OBJETIVO ******************************************************
 * O programa deve ser capaz de gerar um labirinto e resolvê-lo. Resolver o labirinto significa que ao
 * simular um objeto que percorre o mesmo e que este ache a saída a partir de um ponto de partida.
 * 
 * O programa deve conter 2 funções:
 *    - Função para gerar o labirinto a partir de uma matriz 12x12;
 *    - Função para achar a saída do labirinto gerado.
 * 
 * No labirinto, blocos (█) representam paredes e pontos ('.') representam caminho livre. A cada quadrado
 * percorrido deve-se colocar um '+', se o caminho já foi percorrido (caractere '+' já inserido na posição)
 * e for percorrido novamente deve-se colocar um 'x'.
 * Somente 4 ações são possíveis: ir para cima, para baixo, para esquerda e direita
 * 
 * Existe um algoritmo simples para percorrer um labirinto que garante encontrar a saída (supondo que
 * exista uma saída). Se não houver uma saída, você chegará ao local de partida novamente:
 *    - Coloque a mão direita na parede à direita e comece a andar para frente;
 *    - Nunca retire sua mão da parede;
 *    - Se o labirinto virar para a direita, siga a parede para a direita;
 *    - Contanto que você não remova a mão da parede, você chegará à saída do labirinto em algum momento;
 *    - Pode haver um caminho mais curto do que o que você seguiu. Contudo, este algoritmo garante que você
 *      consegue sair do labirinto.
 * 
 * AUTHOR: GuhPires (Gustavo G. Pires, RA: 11.219.056-6)
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

#define MAZE_SIZE 5

// void generateMaze(int, int, char(*)[*], int);

int main(void) {
  char *wall = "\u2588";
  char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'|', '|', '|', '|', '|'},
    {'|', '|', '|', '|', '|'},
    {'+', '.', '.', '.', '.'},
    {'|', '|', '|', '|', '|'},
    {'|', '|', '|', '|', '|'}
  };
  for(int i = 0; i < MAZE_SIZE; i++) {
    for(int j = 0; j < MAZE_SIZE; j++){
      printf("%c", maze[i][j]);
    }
      printf("\n");
  }
}

/**
 * 
 * DESCRIPTION: Gera um labirinto em uma matriz quadrada.
 * @param       lines número de linhas da matriz
 * @param       columns número de colunas da matriz
 * @param       matrix instância da matriz do labirinto
 * @param       test_case inteiro que define qual teste deve ser criado. Cada número gera um tipo diferente
 *                        de labirinto para teste.
 * @returns     NONE
 * 
**/
// void generateMaze(int lines, int columns, char matrix[lines][columns], int test_case) {
//   switch(test_case){
//     case 0:
//       char maze[5][5] = {
//         {"\u2588", "\u2588", "\u2588", "\u2588", "\u2588"},
//         {"\u2588", "\u2588", "\u2588", "\u2588", "\u2588"},
//         {'+', '.', '.', '.', '.'},
//         {"\u2588", "\u2588", "\u2588", "\u2588", "\u2588"},
//         {"\u2588", "\u2588", "\u2588", "\u2588", "\u2588"}
//       };
//       memcpy(matrix, maze, sizeof(matrix));
//     break;
//     case 1:
//       char maze[5][5] = {
//         {"\u2588", "\u2588", '+', "\u2588", "\u2588"},
//         {"\u2588", "\u2588", '.', "\u2588", "\u2588"},
//         {"\u2588", "\u2588", '.', "\u2588", "\u2588"},
//         {"\u2588", "\u2588", '.', "\u2588", "\u2588"},
//         {"\u2588", "\u2588", '.', "\u2588", "\u2588"}
//       };
//       memcpy(matrix, maze, sizeof(matrix));
//     break;
//     case 2:
//       char maze[5][5] = {
//           {'+', '.', '.', "\u2588", "\u2588"},
//           {"\u2588", "\u2588", '.', "\u2588", "\u2588"},
//           {"\u2588", "\u2588", '.', "\u2588", "\u2588"},
//           {"\u2588", "\u2588", '.', "\u2588", "\u2588"},
//           {"\u2588", "\u2588", '.', "\u2588", "\u2588"}
//         };
//       memcpy(matrix, maze, sizeof(matrix));
//     break;
//     case 3:
//       char maze[5][5] = {
//         {"\u2588", "\u2588", '.', '.', '+'},
//         {"\u2588", "\u2588", '.', "\u2588", "\u2588"},
//         {"\u2588", "\u2588", '.', "\u2588", "\u2588"},
//         {"\u2588", "\u2588", '.', "\u2588", "\u2588"},
//         {"\u2588", "\u2588", '.', "\u2588", "\u2588"}
//       };
//       memcpy(matrix, maze, sizeof(matrix));
//     break;
//     case 4:
//       char maze[5][5] = {
//         {"\u2588", "\u2588", '.', "\u2588", "\u2588"},
//         {"\u2588", "\u2588", '.', "\u2588", "\u2588"},
//         {"\u2588", "\u2588", '.', "\u2588", "\u2588"},
//         {"\u2588", "\u2588", '.', "\u2588", "\u2588"},
//         {"\u2588", "\u2588", '.', '.', '+'}
//       };
//       memcpy(matrix, maze, sizeof(matrix));
//     break;
//     case 5:
//       char maze[5][5] = {
//           {"\u2588", "\u2588", '.', "\u2588", "\u2588"},
//           {"\u2588", "\u2588", '.', "\u2588", "\u2588"},
//           {"\u2588", "\u2588", '.', "\u2588", "\u2588"},
//           {"\u2588", "\u2588", '.', "\u2588", "\u2588"},
//           {'+', '.', '.', "\u2588", "\u2588"}
//         };
//         memcpy(matrix, maze, sizeof(matrix));
//     break;
//     default:
//       char maze[5][5] = {
//         {"\u2588", "\u2588", "\u2588", "\u2588", "\u2588"},
//         {"\u2588", "\u2588", "\u2588", "\u2588", "\u2588"},
//         {'+', '.', '.', '.', '.'},
//         {"\u2588", "\u2588", "\u2588", "\u2588", "\u2588"},
//         {"\u2588", "\u2588", "\u2588", "\u2588", "\u2588"},
//       };
//       memcpy(matrix, maze, sizeof(matrix));
//     break;
//   }
// }