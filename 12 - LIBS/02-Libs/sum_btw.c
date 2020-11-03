#include "sum_btw.h"

int sum_nums_btw(int a, int b) {
  int sm = a, lg = b;
  if(a > b) {
    sm = b;
    lg = a;
  }
  int sum = 0;
  for(int i = sm + 1; i < lg; i++) {
    sum += i;
  }
  return sum;
}