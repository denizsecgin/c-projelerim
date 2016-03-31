/*************************************
 * Shell Sort
 ************************************/

void shell_sort(int *array, int size) {
  /* Sedgewick tarafindan belirlenen gap serisi */
  int gaps[] = {4193, 1073, 281, 77, 23, 8, 1};
  int i, j, k;

  for (k = 0; k < sizeof(gaps) / sizeof(int); ++k) {
    int g = gaps[k];
    for (i = g; i < size; i += 1) {
      int pivot = array[i];
      int j = i;
      while (j >= g && array[j - g] > pivot) {
        array[j] = array[j - g];
        j = j - g;
      }
      array[j] = pivot;
    }
  }
}

void ciura_shell_sort(int *array, int size) {
  /* Ciura tarafindan belirlenen gap serisi */
  int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
  int i, j, k;

  for (k = 0; k < sizeof(gaps) / sizeof(int); ++k) {
    int g = gaps[k];
    for (i = g; i < size; i += 1) {
      int pivot = array[i];
      int j = i;
      while (j >= g && array[j - g] > pivot) {
        array[j] = array[j - g];
        j = j - g;
      }
      array[j] = pivot;
    }
  }
}


