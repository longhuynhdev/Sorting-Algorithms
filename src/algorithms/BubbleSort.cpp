#include "BubbleSort.h"
#include "DataGenerator.h"
#include "SortingAlgorithmRegistry.h"

void BubbleSort::sortImp(int arr[], int n) {
  for (int i = 0; ++count_compare && i < n - 1; i++) {
    for (int j = 0; ++count_compare && j < n - i - 1; j++) {
      if (++count_compare && arr[j] > arr[j + 1]) {
        HoanVi(arr[j], arr[j + 1]);
      }
    }
  }
}

std::string BubbleSort::getName() const { return "Bubble Sort"; }

REGISTER_ALGORITHM("bubble-sort", BubbleSort)
