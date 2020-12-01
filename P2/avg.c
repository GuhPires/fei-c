#include "avg.h"

float calc_avg(int *grades, int tests_num) {
  float sum = 0;
  for(int i = 0; i < tests_num; i++) {
    sum += grades[i];
  }
  return sum / tests_num;
}