/******************************************* OBJETIVO ******************************************************
 * Implemente uma agenda composta por pessoas. Cada pessoa tem os seguintes campos: nome, idade, telefone,
 * endereço, cidade, estado e cep.
 *    a. Crie a struct
 *    b. Crie um vetor de 100 registros
 *    c. Crie um procedimento para inserir um registro na agenda
 *    d. Crie um procedimento para remover um registro da
 *       agenda
 *    e. Crie um procedimento para buscar um registro pelo nome
 * 
 * AUTHOR: GuhPires
 * VISIT: https://github.com/GuhPires/fei-c
 **********************************************************************************************************/

#include <stdio.h>
#include <string.h>

struct person {
  char name[50];
  int age;
  int phone;
  char address[200];
  char city[100];
  char state[50];
  int zip_code;
};

void add_person(struct person*, struct person);
void delete_person(struct person*, struct person);
struct person find_by_name(struct person*, char*);
void show_agenda(struct person*);

int lst_idx = 0;

int main(void) {
  struct person agenda[100];

  strcpy(agenda[0].name, "Gustavo");
  agenda[0].age = 21;
  agenda[0].phone = 123;
  strcpy(agenda[0].address, "Rua A");
  strcpy(agenda[0].city, "São Paulo");
  strcpy(agenda[0].state, "SP");
  agenda[0].zip_code = 198;

  strcpy(agenda[1].name, "Beto");
  agenda[1].age = 30;
  agenda[1].phone = 456;
  strcpy(agenda[1].address, "Rua B");
  strcpy(agenda[1].city, "Santo André");
  strcpy(agenda[1].state, "SP");
  agenda[1].zip_code = 123;

  strcpy(agenda[2].name, "Carla");
  agenda[2].age = 25;
  agenda[2].phone = 789;
  strcpy(agenda[2].address, "Rua C");
  strcpy(agenda[2].city, "São Bernardo do Campo");
  strcpy(agenda[2].state, "SP");
  agenda[2].zip_code = 000;

  add_person(agenda, agenda[0]);
  add_person(agenda, agenda[1]);
  add_person(agenda, agenda[2]);

  show_agenda(agenda);

  struct person p = find_by_name(agenda, "Carla");

  printf("==== Dados da pessoa encontrada ====\n");
  printf("Nome: %s\n", p.name);
  printf("Idade: %d\n", p.age);
  printf("Telefone: %d\n", p.phone);
  printf("Endereço: %s\n", p.address);
  printf("Cidade: %s\n", p.city);
  printf("Estado: %s\n", p.state);
  printf("CEP: %d\n", p.zip_code);

  delete_person(agenda, agenda[1]);

  show_agenda(agenda);

  return 0;
}

void add_person(struct person agenda[], struct person p) {
  agenda[lst_idx] = p;
  lst_idx++;
  printf("\n%s adicionado(a)!\n\n", p.name);
}

void delete_person(struct person agenda[], struct person p) {
  int shift_values = 0;
  for(int i = 0; i < lst_idx; i++) {
    if(shift_values) {
      agenda[i - 1] = agenda[i];
    }
    if(!strcmp(agenda[i].name, p.name)){
      shift_values = 1;
    }
  }
  lst_idx--;
  printf("\n%s removido(a)!\n\n", p.name);
}

struct person find_by_name(struct person agenda[], char name[]) {
  struct person found = agenda[0];
  for(int i = 0; i < lst_idx; i++){
    if(!strcmp(agenda[i].name, name)) {
      found = agenda[i];
      printf("\n%s foi encontrado(a)!\n\n", name);
      break;
    }
  }
  return found;
}

void show_agenda(struct person agenda[]) {
  for(int i = 0; i < lst_idx; i++){
    printf("----------------------------------\n");
    printf("Nome: %s\n", agenda[i].name);
    printf("Idade: %d\n", agenda[i].age);
    printf("Telefone: %d\n", agenda[i].phone);
    printf("Endereço: %s\n", agenda[i].address);
    printf("Cidade: %s\n", agenda[i].city);
    printf("Estado: %s\n", agenda[i].state);
    printf("CEP: %d\n", agenda[i].zip_code);
    printf("----------------------------------\n");
  }
}