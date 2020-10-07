/******************************************* OBJETIVO ******************************************************
 * O programa deve ser capaz de gerar um labirinto e resolvê-lo. Resolver o labirinto significa que ao
 * simular um objeto que percorre o mesmo e que este ache a saída a partir de um ponto de partida.
 * 
 * O programa deve conter 2 funções:
 *    - Função para gerar o labirinto a partir de uma matriz 12x12;
 *    - Função para achar a saída do labirinto gerado.
 * 
 * No labirinto, blocos (#) representam paredes e pontos ('.') representam caminho livre. A cada quadrado
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
 * OBS: Ao trabalhar com matrizes os eixos X e Y são trocados e invertidos, pois pela definição de matriz: 
 *      [linha][coluna], ou seja, [Y][X]. São invertidos pois a posição [0][0] é no topo à esquerda (segue
 *      exemplo).
 * EXAMPLE:
 *      Plano Cartesiano Padrão:      Plano Cartesiano "Matricial"
 *      y                                   0 ------------ coluna (j)
 *      |                                   |  
 *      |                                   |
 *      |                                   |
 *      0 ------------ x                  linha (i)
 * 
 * OBS: Para saber qual é o lado direito, é necessário que se saiba qual a direção o objeto que percorrerá o
 *      labirinto está apontando, portanto, a variável 'direction' controla isso. Os possíveis valores estão
 *      listados no exemplo abaixo.
 * EXAMPLE:
 *                        N (north/norte)    E (east/leste)    S (south/sul)   W (west/oeste)                                    
 *                                ↑               + →                +              ← +
 *                                +                                  ↓  
 * 
 * AUTHOR: GuhPires (Gustavo G. Pires, RA: 11.219.056-6)
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

#define MAZE_SIZE 5

// CONSTANTS
char wall = '#', path = '.', pos = '+', d_pos = 'x', direction = 'E';

// HELPER FUNCTIONS
void print_maze(char[MAZE_SIZE][MAZE_SIZE]);
void get_positions(int*, int*, char[MAZE_SIZE][MAZE_SIZE]);
char get_direction(int, int, char[MAZE_SIZE][MAZE_SIZE]);
void step(int*, int*);
void turn();

// MAIN FUNCTIONS
// void generate_maze(int, int, char(*)[*], int);
void solve_maze(char[MAZE_SIZE][MAZE_SIZE]);

int main(void) {
  int init_pos[2], end_pos[2];
  char maze[MAZE_SIZE][MAZE_SIZE] = {
    {wall, wall, wall, wall, wall},
    {wall, wall, wall, wall, wall},
    {pos, path, path, path, path},
    {wall, wall, wall, wall, wall},
    {wall, wall, wall, wall, wall}
  };
  print_maze(maze);
  get_positions(init_pos, end_pos, maze);
  printf("Start @ (%d, %d); End @ (%d, %d)\n", init_pos[1], init_pos[0], end_pos[1], end_pos[0]);
}

/**
 * 
 * DESCRIPTION: Imprime o labirinto desejado.
 * @param       matrix instância da matriz do labirinto
 * @returns     NONE
 * 
**/
void print_maze(char matrix[MAZE_SIZE][MAZE_SIZE]) {
  for(int i = 0; i < MAZE_SIZE; i++) {
    for(int j = 0; j < MAZE_SIZE; j++){
      printf("\t%c", matrix[i][j]);
    }
      printf("\n");
  }
}

/**
 * 
 * DESCRIPTION: Descobre a posição inicial e final do labirinto, passa os valores encontrados por
 *              referência, ou seja, altera os valores dos endereços passados como parâmetros.
 * @param       start array contendo as posições iniciais
 * @param       end array contendo as posições finais
 * @param       matrix instância da matriz do labirinto
 * @returns     NONE
 * 
**/
void get_positions(int *start, int *end, char matrix[MAZE_SIZE][MAZE_SIZE]) {
  // i = y; j = x (matrix [lines][columns] or matrix [y][x])
  for(int i = 0; i < MAZE_SIZE; i++) {
    for(int j = 0; j < MAZE_SIZE; j++) {
      if((i == 0 || i == MAZE_SIZE - 1) || (j == 0 || j == MAZE_SIZE - 1)) {
        // printf("POSITION (%d,%d); CHARACTER: %c\n", j, i, matrix[i][j]);
        if(matrix[i][j] == pos) {
          start[0] = i;
          start[1] = j;
        } else if(matrix[i][j] == path) {
          end[0] = i;
          end[1] = j;
        }
      } else {
        continue;
      }
    }
  }
}

char get_direction(int x, int y, char matrix[MAZE_SIZE][MAZE_SIZE]) {

}

/**
 * 
 * DESCRIPTION: Dá um passo para frente, levando em consideração a direção atual (variável
 *              global 'direction'). Os parâmetros são passados por referência (enereços) e
 *              têm seus valores modificados dentro da função.
 * @param       x atual posição X do objeto
 * @param       y atual posição Y do objeto
 * @returns     NONE
 * 
**/
void step(int *x, int *y) {
  switch(direction) {
    case 'N':
      direction = 'E';
    break;
    case 'E':
      direction = 'S';
    break;
    case 'S':
      direction = 'W';
    break;
    case 'W':
      direction = 'N';
    break;
  }
}

/**
 * 
 * DESCRIPTION: Gira 90º na direção horária, função que modifica a variável 'direction' que
 *              está no escopo global.
 * @param       NONE
 * @returns     NONE
 * 
**/
void turn() {
  switch(direction) {
    case 'N':
      direction = 'E';
    break;
    case 'E':
      direction = 'S';
    break;
    case 'S':
      direction = 'W';
    break;
    case 'W':
      direction = 'N';
    break;
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
// void generate_maze(int lines, int columns, char matrix[lines][columns], int test_case) {
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

void solve_maze(char matrix[MAZE_SIZE][MAZE_SIZE]) {

}