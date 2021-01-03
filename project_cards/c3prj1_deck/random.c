#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void assert_no_repetitions (int *array) {
    // have to check if the values occur exactly once

  unsigned char isUsed[52] = {0};
  
  for (int index = 0; index < 52; index++) {
    int num = array[index];
    if (isUsed[num])
      printf("Num %d is taken\n", num);

    assert(!isUsed[num]);
    isUsed[num] = 1;
  }
}


int main () {

  unsigned size = 52;
  int num_arr[size];

  // filling array with numbers
  for (int index = 0; index < size; index++) {
    num_arr[index] = index;
  }

  int num, swap;
  for (int index = 0; index < size; index++) {
    unsigned gen_pos = random() % 52;
    swap = num_arr[gen_pos];	/* number to swap */
    num = num_arr[index];
    num_arr[index] = swap;
    num_arr[gen_pos] = num;
  }
  
  for (int index = 0; index < size; index++) {
    printf("[%d] = %d\n", index, num_arr[index]);
  }

  assert_no_repetitions(num_arr);
  printf("No repetitions\n");
  
  return 0;
}
