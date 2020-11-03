#include "join.h"

void join_set(char *l, int *n, char *p) {
  // Pattern: AAA0A00
  p[0] = l[0];
  p[1] = l[1];
  p[2] = l[2];
  p[3] = n[0] + '0';
  p[4] = l[3];
  p[5] = n[1] + '0';
  p[6] = n[2] + '0';
}