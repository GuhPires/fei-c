/******************************************* OBJETIVO ******************************************************
 * Escreva um programa que recebe duas structs de dia-mês-ano, cada uma representando uma data válida. Uma
 * struct deve receber o dia de nascimento de uma pessoa. A outra deve receber a data atual. O programa
 * deve calcular a idade da pessoa.
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

struct date {
  // 1 ~ 30
  int day;
  // 1 ~ 12
  int month;
  int year;
};

void time_alive(struct date, struct date);

int main(void) {
  struct date dates[2];
  dates[0].day = 12;
  dates[0].month = 12;
  dates[0].year = 1998;
  dates[1].day = 13;
  dates[1].month = 10;
  dates[1].year = 2020;
  time_alive(dates[0], dates[1]);
  return 0;
}

void time_alive(struct date birth, struct date now) {
  int days = 0, months = 0, years = 0;
  years += now.year - birth.year;
  months += now.month - birth.month;
  days += now.day - birth.day;
  if(birth.day > now.day) {
    months -= 1;
    days += 30;
  }
  if(birth.month > now.month) {
    years -= 1;
    months += 12;
  }
  printf("Sua idade é %d anos, %d meses, %d dias\n", years, months, days);
}