c

#include <stdio.h>

int main(void) {
  int bills_qty[5], withdraw;
  printf("Digite quanto deseja sacar (entre R$ 10 e R$ 1000 e sempre um número inteiro): ");
  scanf("%d", &withdraw);

  if(withdraw >= 10 && withdraw <= 1000) {
    int value = withdraw / 100;
    bills_qty[0] = value;
    int remainder = withdraw % 100;

    value = remainder / 50;
    bills_qty[1] = value;
    remainder %= 50;
    
    value = remainder / 10;
    bills_qty[2] = value;
    remainder %= 10;
    
    value = remainder / 5;
    bills_qty[3] = value;
    remainder %= 5;
    
    value = remainder / 1;
    bills_qty[4] = value;

    printf("Você receberá %d nota(s) de 100, %d nota(s) de 50, %d nota(s) de 10, %d nota(s) de 5 e %d nota(s) de 1\n", bills_qty[0], bills_qty[1], bills_qty[2], bills_qty[3], bills_qty[4]);
  } else {
    printf("Valor de saque não permitido...\n");
  }

  return 0;
}