#include <stdlib.h>
#include <math.h>

static int _temp;

/* a ve b parametrelerini degistiren makro */
#define SWAP(a,b) do { \
  _temp = a; \
  a = b; \
  b = _temp; \
} while (0)

void max_heapify_iterative(int *array, int start, int end) {
  /* Sol cocugun dizi indeksini hesapla */
  int left = 2*start + 1;
 
  /* Sag cocugun dizi indeksini hesapla */
  int right = left + 1;

  /* Buyuk eleman olarak parent yani start'i kaydet */
  int largest = start;

  while (left <= end) {
    right = left + 1;

    /* Sol cocuk parent'tan buyukse kaydet */
    if (array[largest] < array[left])
      largest = left;

    /* Sag cocuk kayitli buyukten buyukse kaydet */
    if (right <= end && array[largest] < array[right])
      largest = right;

    /* Cocuklardan biri buyuk olarak kaydedildiyse
     * parent ile onu degistirip ilgili degisken
     * atamalarini yap. */
    if (largest != start) {
      SWAP(array[start], array[largest]);
      start = largest;
      left = 2*start + 1;
    }
    /* Degisiklik olmadiysa donguden cik */
    else
      break;
  }
}

void max_heapify_recursive(int *array, int start, int end) {
  /* Sol cocugun dizi indeksini hesapla */
  int left = 2*start + 1;

  /* Sag cocugun dizi indeksini hesapla */
  int right = left + 1;

  /* Buyuk eleman olarak parent yani start'i kaydet */
  int largest = start;

  /* Sol cocuk parent'tan buyukse kaydet */
  if (left <= end && array[left] > array[start])
    largest = left;

  /* Sag cocuk kayitli buyukten buyukse kaydet */
  if (right <= end && array[right] > array[largest])
    largest = right;

  /* Cocuklardan biri buyuk olarak kaydedildiyse
   * parent ile onu degistirip, yeni buyuk icin
   * rekursif cagri yap */
  if (largest != start) {
    SWAP(array[start], array[largest]);
    max_heapify_recursive(array, largest, end);
  }
}

#define max_heapify max_heapify_iterative

void heap_sort_wrapper(int *array, int size) {
  /* heap'i olusturun */
  for (int i = size/2 -1; i >= 0; --i) {
    max_heapify(array, i, size - 1);
  }

  /* Ilk elemani (daima en buyuk) sondakiyle
   * degistirip, dizinin boyutunu 1 azaltarak
   * heap'i duzeltin. */
  for (int i = size - 1; i > 0; ) {
    SWAP(array[0], array[i]);
    max_heapify(array, 0, --i);
  }
}
