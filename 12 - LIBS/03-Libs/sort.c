#include "sort.h"

void sort_array(int *arr, int s) {
  for(int i = 0; i < s; i++) {
    for(int j = 0; j < s; j++) {
      if(arr[j] > arr[i]) {
        int tmp = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;
      }
    }
  }
}