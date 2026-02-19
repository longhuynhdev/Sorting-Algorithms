#include "InsertionSort.h"
#include "SortingAlgorithmRegistry.h"

void InsertionSort::sortImp(int arr[], int n) {
  for (int i = 1; ++count_compare && i < n; i++) {

    int key = arr[i];
    int j = i - 1;

    while (++count_compare && j >= 0 && ++count_compare && key < arr[j]) {
      arr[j + 1] = arr[j];
      --j;
    }

    arr[j + 1] = key;
  }
}

std::string InsertionSort::getName() const { return "Insertion Sort"; }

REGISTER_ALGORITHM("insertion-sort", InsertionSort)
