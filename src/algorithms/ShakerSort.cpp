#include "ShakerSort.h"
#include "DataGenerator.h"
#include "SortingAlgorithmRegistry.h"

void ShakerSort::sortImp(int arr[], int n) {
  int k = 0;
  int left = 0;
  int right = n - 1;

  while (++count_compare && left < right) {
    for (int i = left; ++count_compare && i < right; i++) {
      if (++count_compare && arr[i] > arr[i + 1]) {
        HoanVi(arr[i], arr[i + 1]);
        k = i;
      }
    }
    right = k;

    for (int i = right; ++count_compare && i > left; i--) {
      if (++count_compare && arr[i] < arr[i - 1]) {
        HoanVi(arr[i], arr[i - 1]);
        k = i;
      }
    }
    left = k;
  }
}

std::string ShakerSort::getName() const { return "Shaker Sort"; }

REGISTER_ALGORITHM("shaker-sort", ShakerSort)
