#include "SelectionSort.h"
#include "DataGenerator.h"
#include "SortingAlgorithmRegistry.h"

void SelectionSort::sortImp(int arr[], int n) {
  for (int i = 0; ++count_compare && i < n - 1; i++) {

    // dung 1 bien luu chi so cua phan tu nho nhat
    int min_pos = i;

    // duyet tung phan tu dung sau phan tu hien tai va cap nhat chi so cua phan
    // tu nho nhat
    for (int j = i + 1; ++count_compare && j < n; j++) {
      if (++count_compare && arr[j] < arr[min_pos]) {
        min_pos = j;
      }
    }
    HoanVi(arr[i], arr[min_pos]);
  }
}

std::string SelectionSort::getName() const { return "Selection Sort"; }

REGISTER_ALGORITHM("selection-sort", SelectionSort)
