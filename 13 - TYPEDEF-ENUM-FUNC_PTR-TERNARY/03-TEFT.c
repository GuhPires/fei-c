/******************************************* OBJETIVO ******************************************************
 * Faça um programa em C com uma função que recebe o dia, o mês (como enum) e o ano e retorna o próximo dia.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

enum months {
  jan = 1,
  feb,
  mar,
  apr,
  may,
  jun,
  jul,
  aug,
  sep,
  oct,
  nov,
  dec
};

int date_logic(int*, enum months*, int*);

int main(void) {
  enum months month;
  int day, year;
  printf("Digite uma data separada por espaços (EX: 10/05/2020 = 10 5 2020): ");
  scanf("%d %d %d", &day, &month, &year);
  int valid_date = date_logic(&day, &month, &year);
  if(valid_date) printf("Próximo dia é %d/%d/%d\n", day, month, year);
  return 0;
}

int date_logic(int *day, enum months *month, int *year) {
  if(*day < 0) {
    printf("Data inválida!\n");
    return 0;
  }

  int day_num;
  switch (*month) {
  case jan:
  case mar:
  case may:
  case jul:
  case aug:
  case oct:
  case dec:
    day_num = 31;
    break;
  case feb:
    day_num = 28;
    break;
  case apr:
  case jun:
  case sep:
  case nov:
    day_num = 30;
    break;
  default:
    printf("Data inválida!\n");
    return 0;
  }

  if(*month == dec) { 
    *month = jan;
    (*year)++;
    *day = 1 + ((*day) - day_num);
  } else if(*day >= day_num) {
      (*month)++;
      *day = 1 + ((*day) - day_num);
  } else {
    (*day)++;
  }
  return 1;
}