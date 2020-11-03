#include "hypotenuse.h"

float calc_hypotenuse(float c1, float c2) {
  return sqrtf(powf(c1, 2) + powf(c2, 2));
}