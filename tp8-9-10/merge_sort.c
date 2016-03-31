#include <stdlib.h>

void merge(int *array, int low, int middle, int high) {
  int i = 0, l = 0, r = 0;

  /* Sol yarim listenin boyunu hesaplayin */
  int left_length = middle - low + 1;

  /* Sag yarim listenin boyunu hesaplayin */
  int right_length = high - middle;

  /* Sol ve sag yarim liste icin dizi tanimlayin */
  int left_array[left_length];
  int right_array[right_length];

  /* Sol yarim listeyi sinirlarina gore doldurun */
  for (i = low; i <= middle; ++i) {
    left_array[i - low] = array[i];
  }

  /* Sag yarim listeyi sinirlarina gore doldurun */
  for (i = middle + 1; i <= high; ++i) {
    right_array[i - middle - 1] = array[i];
  }

  /* Birlestirme: Sol ve sag yarim listeleri kendi aralarinda
   * karsilastirarak listenin ilgili yerine yerlestirin.
   * iki yarim listeden birinin sonuna gelindiginde donguden cikilmalidir. */
  for (i = low; l < left_length && r < right_length; ++i) {
    if (left_array[l] <= right_array[r])
      array[i] = left_array[l++];
    else
      array[i] = right_array[r++];
  }

  /* Yarim listelerin tum elemanlari listenin ilgili yerine
   * sokulmadiysa, kalan elemanlari yerlestirin. */
  for (; l < left_length; ++i, ++l) {
    array[i] = left_array[l];
  }
  for (; r < right_length; ++i, ++r) {
    array[i] = right_array[r];
  }
}

void merge_sort(int *array, int low, int high) {
  /* Eger elde kalan liste tek elemanli degilse */
  if (low < high) {
    /* Orta nokta */
    int middle = (low + high) / 2;

    /* Sol tarafi ozyinelemeli olarak siralayin */
    merge_sort(array, low, middle);

    /* Sag tarafi ozyinelemeli olarak siralayin */
    merge_sort(array, middle + 1, high);

    /* Siralanmis listeleri birlestirin */
    merge(array, low, middle, high);
  }
}

void merge_sort_wrapper(int *array, int size) {
  merge_sort(array, 0, size - 1);
}
