/******************************************* OBJETIVO ******************************************************
 * Faça um programa que faça 5 perguntas para uma pessoa sobre um crime. As perguntas são:
 *  - “Telefonou para a vítima?”
 *  - “Esteve no local do crime?”
 *  - ”Mora perto da vítima?”
 *  - “Devia para a vítima?”
 *  - “Já trabalhou com a vítima?”
 * Então, o programa deve emitir uma classificação sobre a participação da pessoa no crime. Se a pessoa
 * responder positivamente a 2 questões, ela deve ser classificada como "Suspeita", entre 3 e 4 como
 * "Cúmplice" e 5 como "Assassino". Caso contrário, ele será classificado como "Inocente".
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>

int show_question(char question[50]) {
  char answer = '\0';
  int valid_answer = -1;
  printf("%s [S/N]: ", question);
  // IMPORTANTE: Use " %c" ao invés de "%c" para que funcione (ignora espaços)
  scanf(" %c", &answer);
  switch(answer) {
    case 'S':
    case 's':
      valid_answer = 1;
      break;
    case 'N':
    case 'n':
      valid_answer = 0;
      break;
    default:
      printf("Opção inválida, tente novamente...\n");
      valid_answer = -1;
  }
  if(valid_answer >= 0) {
    return valid_answer;
  } else {
    return -1;
  }
}

int main(void) {
  int positive_counter = 0;
  int valid;
  printf("Responda as seguintes perguntas com apenas S (para 'sim') e N (para 'não')...\n");

  // OBS: Solução sem o uso de Loops

  valid = show_question("Telefonou para a vítima?");
  if(valid > -1) {
    positive_counter += valid;
  } else {
    return 0;
  }

  valid = show_question("Esteve no local do crime?");
  if(valid > -1) {
    positive_counter += valid;
  } else {
    return 0;
  }

  valid = show_question("Mora perto da vítima?");
  if(valid > -1) {
    positive_counter += valid;
  } else {
    return 0;
  }

  valid = show_question("Devia para a vítima?");
  if(valid > -1) {
    positive_counter += valid;
  } else {
    return 0;
  }

  valid = show_question("Já trabalhou com a vítima?");
  if(valid > -1) {
    positive_counter += valid;
  } else {
    return 0;
  }

  if(positive_counter == 2) {
    printf("Você é SUSPEITO!\n");
  } else if(positive_counter == 3 || positive_counter == 4) {
    printf("Você é CÚMPLICE!\n");
  } else if(positive_counter == 5) {
    printf("Você é o ASSASSINO!\n");
  } else {
    printf("Você é INOCENTE!\n");
  }

  return 0;
}