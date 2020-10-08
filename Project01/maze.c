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
 *      Plano Cartesiano Padrão:      Plano Cartesiano "Matricial"            Plano Cartesiado Adotado
 *      +y                                  0 ------------ coluna (j)             0 ------------ +x
 *      |                                   |                                     |
 *      |                                   |                                     |
 *      |                                   |                                     |
 *      0 ------------ +x                  linha (i)                              +y
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
char wall = '#', path = '.', pos = '+', d_pos = 'x', direction;

// HELPER FUNCTIONS
void print_maze(char[MAZE_SIZE][MAZE_SIZE], int);
void get_positions(int*, int*, char[MAZE_SIZE][MAZE_SIZE]);
int is_wall_on(char, int, int, char[MAZE_SIZE][MAZE_SIZE]);
void step(int*, int*, char[MAZE_SIZE][MAZE_SIZE]);
void turn();

// MAIN FUNCTIONS
// void generate_maze(int, int, char(*)[*], int);
void solve_maze(char[MAZE_SIZE][MAZE_SIZE]);

int main(void) {
  char maze[MAZE_SIZE][MAZE_SIZE] = {
    {wall, wall, wall, wall, wall},
    {wall, wall, wall, wall, wall},
    {pos, path, path, path, path},
    {wall, wall, wall, wall, wall},
    {wall, wall, wall, wall, wall}
  };
  solve_maze(maze);
}

/**
 * 
 * DESCRIPTION: Imprime o labirinto desejado.
 * @param       matrix instância da matriz do labirinto
 * @param       axis controla se os eixos devem ser impressos (0 = false, 1 = true)
 * @returns     NONE
 * 
**/
void print_maze(char matrix[MAZE_SIZE][MAZE_SIZE], int axis) {
  printf("\n");
  for(int i = 0; i < MAZE_SIZE; i++) {
    if(axis == 1 && i == 0) {
      printf("\t");
      for(int k = 0; k < MAZE_SIZE; k++) {
        printf("\t[%d]", k);
      }
      printf("\n");
    }
    for(int j = 0; j < MAZE_SIZE; j++){
      if(axis == 1 && j == 0) printf("\t[%d]", i);
      printf("\t %c ", matrix[i][j]);
    }
      printf("\n");
  }
}

/**
 * 
 * DESCRIPTION: Descobre a posição inicial e final do labirinto, passa os valores encontrados por
 *              referência, ou seja, altera os valores dos endereços passados como parâmetros.
 *              Esta função também define a direção inicial.
 * @param       start array contendo as posições iniciais
 * @param       end array contendo as posições finais
 * @param       matrix instância da matriz do labirinto
 * @returns     NONE
 * 
**/
void get_positions(int *start, int *end, char matrix[MAZE_SIZE][MAZE_SIZE]) {
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
  // Define a direção inicial
  if(start[0] == 0) {
    direction = 'S';
  } else if(start[0] == MAZE_SIZE - 1) {
    direction = 'N';
  } else if(start[1] == MAZE_SIZE - 1) {
    direction = 'W';
  } else {
    direction = 'E';
  }
}

/**
 * 
 * DESCRIPTION: Verifica se existe uma parede à direita ou a frente da posição atual do objeto,
 *              dependendo também da atual direção do objeto.
 * @param       side lado que deseja verificar a existênca de uma parede. One 'F' para front
 *                   (frente), 'R' para right (direita)
 * @param       x atual posição X
 * @param       y atual posição Y
 * @param       matrix instância da matriz do labirinto
 * @returns     NONE
 * 
**/
int is_wall_on(char side, int x, int y, char matrix[MAZE_SIZE][MAZE_SIZE]) {
  if(side != 'R' && side != 'F') return -1;
  switch(direction) {
    case 'N':
      if(side == 'R') {
        if(x + 1 >= MAZE_SIZE) return -1;
        else if(matrix[y][x + 1] == wall) return 1;
        else return 0;
      } else if(side == 'F') {
        if(y - 1 < 0) return -1;
        else if(matrix[y - 1][x] == wall) return 1;
        else return 0;
      }
    break;
    case 'E':
      if(side == 'R') {
        if(y + 1 >= MAZE_SIZE) return -1;
        else if(matrix[y + 1][x] == wall) return 1;
        else return 0;
      } else if(side == 'F') {
        if(x + 1 >= MAZE_SIZE) return -1;
        else if(matrix[y][x + 1] == wall) return 1;
        else return 0;
      }
    break;
    case 'S':
      if(side == 'R') {
        if(x - 1 < 0) return -1;
        else if(matrix[y][x - 1] == wall) return 1;
        else return 0;
      } else if(side == 'F') {
        if(y + 1 >= MAZE_SIZE) return -1;
        else if(matrix[y + 1][x] == wall) return 1;
        else return 0;
      }
    break;
    case 'W':
      if(side == 'R') {
        if(y - 1 < 0) return -1;
        else if(matrix[y - 1][x] == wall) return 1;
        else return 0;
      } else if(side == 'F') {
        if(x - 1 < 0) return -1;
        else if(matrix[y][x - 1] == wall) return 1;
        else return 0;
      }
    break;
    default:
      return -1;
    break;
  }
}

/**
 * 
 * DESCRIPTION: Dá um passo para frente, levando em consideração a direção atual (variável
 *              global 'direction'). Os parâmetros são passados por referência (enereços) e
 *              têm seus valores modificados dentro da função.
 * @param       x atual posição X do objeto
 * @param       y atual posição Y do objeto
 * @param       matrix instância da matriz do labirinto
 * @returns     NONE
 * 
**/
void step(int *x, int *y, char matrix[MAZE_SIZE][MAZE_SIZE]) {
  switch(direction) {
    case 'N':
      *y--;
    break;
    case 'E':
      *x++;
    break;
    case 'S':
      *y++;
    break;
    case 'W':
      *x--;
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
  int start[2], end[2], curr_x = 0, curr_y = 0;
  print_maze(matrix, 1);
  get_positions(start, end, matrix);
  curr_x = start[1];
  curr_y = start[0];
  printf("\n\tStart @ position (%d, %d)\n\tFinish @ position (%d, %d)\n", start[1], start[0], end[1], end[0]);
  printf("\tCurrent Direction: %c\n", direction);

  // Tarefa executada até que o objeto esteja na posição final (x,y)
  // while(1) {
    // Se existir parede a direita
    printf("\tCurrent Position: (%d, %d)", curr_x, curr_y);
    int r_wall = is_wall_on('R', curr_x, curr_y, matrix);
    int f_wall = is_wall_on('F', curr_x, curr_y, matrix);
    if(r_wall == -1 || f_wall == -1) printf("ERRO!");
    if(r_wall) {
      // Se existir parede a frente
      printf("\tParede a direita\n");
      if(f_wall) {
        // turn();
        printf("\tParede a frente\n");
      } else {
        // Siga em frente
        printf("\tSiga!\n");
        // step(&curr_x, &curr_y, matrix);
      }
    } else {
      // Vire
      printf("\tVire e siga!\n");
      // turn();
      // step(&curr_x, &curr_y, matrix);
    }
    // if(curr_x == end[1] && curr_y == end[0]) break;
  // }
  // printf("\tSolução encontrada!\n");
}