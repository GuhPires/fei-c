/******************************************* OBJETIVO ******************************************************
 * O programa deve ser capaz de gerar um labirinto e resolvê-lo. Resolver o labirinto significa que ao
 * simular um objeto que percorre o mesmo, este ache a saída a partir de um ponto de partida.
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
 *      [linha][coluna], ou seja, [Y][X] (trocados). São invertidos pois a posição [0][0] é no topo à esquerda
 *      (segue exemplo).
 * EXAMPLE:
 *      Plano Cartesiano Padrão:      Plano Cartesiano "Matricial"            Plano Cartesiado Adotado
 *      +y                              0 ------------ coluna (j)                 0 ------------ +x
 *      |                               |                                         |
 *      |                               |                                         |
 *      |                               |                                         |
 *      0 ------------ +x             linha (i)                                   +y
 * 
 * OBS: Para saber qual é o lado direito, é necessário que se saiba qual a direção o objeto que percorrerá o
 *      labirinto está apontando, portanto, a variável 'direction' controla isso. Os possíveis valores estão
 *      listados no exemplo abaixo.
 * EXAMPLE:
 *                        N (north/norte)    E (east/leste)    S (south/sul)   W (west/oeste)                                    
 *                                ↑               + →                +              ← +
 *                                +                                  ↓  
 * 
 * ATTENTION: Para a criação e a solução efetiva do labirinto, se admite que o mesmo é rodeado por
 *            paredes, somente o início e o fim podem estar localizados nas bordas, portanto, não
 *            se pode percorrer o labirinto por suas bordas. Isso pode ser considerado como
 *            "Princípio das bordas" (nome que inventei para esta restrição). Veja exemplos abaixo:
 *
 *            CORRETO           ERRADO            CORRETO           ERRADO       
 *           # # # # #        # # # # #          # + # # #         # # # # #     Nota-se que os
 *           # # # # #        # # # # #          # . . . #         # # . . .     labirintos dados
 *           + . . . .        + # # # #          # # # . #         # # . # .     como CORRETOS
 *           # # # # #        . # # # #          # # # . #         # # . # .     são rodeados por
 *           # # # # #        . # # # #          # # # . #         # # + # .     paredes ('#').
 * 
 * ATTENTION: A direção inicial é definida a partir do "princípio das bordas" citado acima, ou seja,
 *            dependendo da da borda onde se é encontrada a posição inicial pode-se definir a direção
 *            inicial do objeto. Veja abaixo os casos:
 *            
 *          Início na borda           Início na borda           Início na borda           Início na borda
 *            da esquerda                 do topo                  da direita                 de baixo
 *              # # #                      # + #                     # # #                      # # #
 *              + # #                      # # #                     # # +                      # # #
 *              # # #                      # # #                     # # #                      # + #
 * 
 *            - Para início na borda da ESQUERDA a única direção permitida é a LESTE ('E');
 *            - Para início na borda do TOPO a única direção permitida é a SUL ('S');
 *            - Para início na borda da DIREITA a única direção permitida é a OESTE ('W');
 *            - Para início na borda de BAIXO a única direção permitida é a NORTE ('N').
 * 
 * AUTHOR: GuhPires (Gustavo G. Pires, RA: 11.219.056-6)
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

// Define o tamanho do labirinto gerado
#define MAZE_SIZE 12

// CONSTANTS
char wall = '#', path = '.', pos = '+', d_pos = 'x', direction;

// HELPER FUNCTIONS
void print_maze(char[MAZE_SIZE][MAZE_SIZE], int);
void get_positions(int*, int*, char[MAZE_SIZE][MAZE_SIZE]);
int is_wall_on(char, int, int, char[MAZE_SIZE][MAZE_SIZE]);
void step(int*, int*, char[MAZE_SIZE][MAZE_SIZE]);
void turn();

// MAIN FUNCTIONS
void generate_maze(char[MAZE_SIZE][MAZE_SIZE]);
void solve_maze(char[MAZE_SIZE][MAZE_SIZE]);

int main(void) {
  char maze[MAZE_SIZE][MAZE_SIZE];
  generate_maze(maze);
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
  printf("\n");
  printf("\n");
  printf("\n");
  for(int i = 0; i < MAZE_SIZE; i++) {
    // Se necessário a impressão dos eixos adotados (a partir do parâmetro 'axis')
    if(axis == 1 && i == 0) {
      printf("\t");
      for(int k = 0; k < MAZE_SIZE; k++) {
        printf("\t[%d]", k);
      }
      printf("\n");
    }
    for(int j = 0; j < MAZE_SIZE; j++){
      // Se necessário a impressão dos eixos adotados (a partir do parâmetro 'axis')
      if(axis == 1 && j == 0) printf("\t[%d]", i);
      printf("\t %c ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

/**
 * 
 * DESCRIPTION: Descobre a posição inicial e final do labirinto, passa os valores encontrados por
 *              referência, ou seja, altera os valores dos endereços passados como parâmetros.
 *              Esta função também define a direção inicial do objeto.
 * @param       start array contendo as posições iniciais
 * @param       end array contendo as posições finais
 * @param       matrix instância da matriz do labirinto
 * @returns     NONE
 * 
**/
void get_positions(int *start, int *end, char matrix[MAZE_SIZE][MAZE_SIZE]) {
  for(int i = 0; i < MAZE_SIZE; i++) {
    for(int j = 0; j < MAZE_SIZE; j++) {
      // Verifica-se o caractere adotado como 'pos' e o caractere adotado como 'path'
      // APENAS nas bordas, pois é onde inicia-se e finaliza-se o labirinto (ver 'ATTENTION'
      // sobre o "princípio das bordas")
      if((i == 0 || i == MAZE_SIZE - 1) || (j == 0 || j == MAZE_SIZE - 1)) {
        // Se a posição atual j, i (ou x, y) possui o caractere de 'pos'
        if(matrix[i][j] == pos) {
          // Atribui-se o início nas coordenadas atuais
          start[0] = i;
          start[1] = j;
        // Se a posição atual j, i (ou x, y) possui o caractere de 'path'
        } else if(matrix[i][j] == path) {
          // Atribui-se o final nas coordenadas atuais
          end[0] = i;
          end[1] = j;
        }
      } else {
        continue;
      }
    }
  }
  // Define a direção inicial a partir das coordenadas X e Y encontradas para o início
  // Ver 'ATTENTION' no topo deste aquivo para uma informação mais detalhada sobre a 
  // lógica adotada para se descobrir a direção inicial do objeto
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
 * DESCRIPTION: Verifica se existe uma parede a direita ou a frente da posição atual do objeto,
 *              dependendo também da atual direção do objeto.
 * @param       side lado que deseja verificar a existênca de uma parede. Onde 'F' para front
 *                   (frente), 'R' para right (direita)
 * @param       x atual posição X
 * @param       y atual posição Y
 * @param       matrix instância da matriz do labirinto
 * @returns     -1 para parâmetros e/ou coordenadas inválidas; 1 para a existência de parede no
 *              lado passado como parâmetro (side); 0 para a inexistência de parede no lado
 *              passado como parâmetro (side).
 * 
**/
int is_wall_on(char side, int x, int y, char matrix[MAZE_SIZE][MAZE_SIZE]) {
  // Verifica se o parâmetro passado como o lado a ser verificado é válido
  if(side != 'R' && side != 'F') return -1;
  // Para melhor entender os eixos adotados e a lógica abaixo, veja a
  // explicação e o plano adotado pelo programa nas observações no topo
  // deste arquivo

  // Verifica se há uma parede no lado passado como parâmetro
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
  return -1;
}

/**
 * 
 * DESCRIPTION: Dá um passo para frente, levando em consideração a direção atual (variável
 *              global 'direction'). Os parâmetros são passados por referência (endereços) e
 *              têm seus valores modificados dentro da função.
 * @param       x atual posição X do objeto
 * @param       y atual posição Y do objeto
 * @param       matrix instância da matriz do labirinto
 * @returns     NONE
 * 
**/
void step(int *x, int *y, char matrix[MAZE_SIZE][MAZE_SIZE]) {
  // Verifica a direção atual e dá um passo a frente
  switch(direction) {
    case 'N':
      (*y)--;
    break;
    case 'E':
      (*x)++;
    break;
    case 'S':
      (*y)++;
    break;
    case 'W':
      (*x)--;
    break;
  }
  // Modifica o caractere que indica o caminho percorrido
  if(matrix[*y][*x] == path) matrix[*y][*x] = pos;
  else matrix[*y][*x] = d_pos;
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
  // Verifica a direção atual e vira na direção horária
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
 * @param       matrix instância da matriz do labirinto
 * @returns     NONE
 * 
**/
void generate_maze(char matrix[MAZE_SIZE][MAZE_SIZE]) {
  char gen_maze[MAZE_SIZE][MAZE_SIZE] = {
    {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall},
    {pos, path, path, path, wall, wall, wall, wall, wall, wall, wall, wall},
    {wall, wall, wall, path, path, path, path, wall, wall, wall, wall, wall},
    {wall, wall, wall, path, wall, wall, path, wall, wall, wall, wall, wall},
    {wall, wall, wall, wall, wall, wall, path, wall, wall, wall, wall, wall},
    {wall, wall, wall, wall, wall, wall, path, wall, wall, wall, wall, wall},
    {wall, wall, path, path, path, path, path, wall, wall, wall, wall, wall},
    {wall, path, path, wall, wall, wall, wall, wall, wall, wall, wall, wall},
    {wall, path, wall, wall, wall, path, path, path, path, path, path, path},
    {wall, path, wall, wall, wall, path, wall, wall, wall, wall, path, wall},
    {wall, path, path, path, path, path, wall, wall, wall, wall, path, wall},
    {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall}
  };
  for(int i = 0; i < MAZE_SIZE; i++) {
    for(int j = 0; j < MAZE_SIZE; j++) {
      matrix[i][j] = gen_maze[i][j];
    }
  }
}

/**
 * 
 * DESCRIPTION: Resolve o labirinto gerado pelo programa/usuário.
 * @param       matrix instância da matriz do labirinto
 * @returns     NONE
 * 
**/
void solve_maze(char matrix[MAZE_SIZE][MAZE_SIZE]) {
  // Variáveis de controle de início, fim e posicionamento
  int start[2], end[2], curr_x = 0, curr_y = 0;
  // Imprime a matriz do labirinto demonstrando os eixos adotados
  print_maze(matrix, 1);
  // Procura por uma posição inicial e final, além da direção inicial do objeto
  get_positions(start, end, matrix);
  // Salva as posições iniciais nas variáveis de controle de posicionamento do objeto
  curr_x = start[1];
  curr_y = start[0];
  printf("\n\tInício em: (%d, %d)\n\tFinal em: (%d, %d)\n", start[1], start[0], end[1], end[0]);
  printf("\tDireção atual: %c\n", direction);
  printf("\n");
  printf("\t---- Solucionando Labirinto... ----\n");
  print_maze(matrix, 0);
  // Tarefa executada até que o objeto esteja na posição final (x,y)
  while(1) {
    // Para efeitos de "animação", cada iteração é pausada por 1.5 segundos
    sleep(1.5);
    printf("\tPosição atual: (%d, %d)\n", curr_x, curr_y);
    // Verifica se existe uma parede a direita do objeto
    int r_wall = is_wall_on('R', curr_x, curr_y, matrix);
    // Verifica se existe uma parede a frente do objeto
    int f_wall = is_wall_on('F', curr_x, curr_y, matrix);
    // Se a posição atual for na borda da matriz (o que é um valor inválido), uma
    // mensagem de erro é aprensentada e o programa é finalizado (veja 'ATTENTION'
    // no topo o programa)
    if(r_wall == -1 || f_wall == -1) {
      printf("---- ERRO! ----\n");
      break;
    }
    // Se existir parede a direita
    if(r_wall) {
      printf("\tParede a direita\n");
      // Se existir parede a frente
      if(f_wall) {
        printf("\tParede a frente\n");
        // Gira na direção ANTI-HORÁRIA (neste caso, gira-se 3x na direção horária para
        // atingir o mesmo resultado e não criar novos casos para a função 'turn()')
        printf("\tVire 3x\n");
        turn();
        turn();
        turn();
      } else {
        // Siga em frente
        printf("\tSem parede a frente\n");
        printf("\tSiga!\n");
        step(&curr_x, &curr_y, matrix);
      }
    } else {
      // Vire e siga em frente na nova direção
      printf("\tSem parede a direita\n");
      printf("\tVire e siga!\n");
      turn();
      step(&curr_x, &curr_y, matrix);
    }
    // Imprime o estado atual do labirinto
    print_maze(matrix, 0);
    // Se a posição atual é igual a posição final significa que uma saída foi encontrada,
    // apresenta-se uma mensagem para o usuário e finaliza o programa
    if(curr_x == end[1] && curr_y == end[0]) {
      printf("\t==== Solução encontrada! ====\n");
      break;
    }
  }
  printf("\n");
  printf("\tFinalizando programa...\n");
}