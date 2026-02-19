#include "HeapSort.h"
#include "DataGenerator.h"
#include "SortingAlgorithmRegistry.h"

void HeapSort::heapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (++count_compare && left < n && ++count_compare &&
      arr[left] > arr[largest]) {
    largest = left;
  }

  if (++count_compare && right < n && ++count_compare &&
      arr[right] > arr[largest]) {
    largest = right;
  }

  if (++count_compare && largest != i) {
    HoanVi(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void HeapSort::sortImp(int arr[], int n) {
  // Build heap
  for (int i = n / 2 - 1; ++count_compare && i >= 0; i--) {
    heapify(arr, n, i);
  }

  for (int i = n - 1; ++count_compare && i >= 0; i--) {
    HoanVi(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

std::string HeapSort::getName() const { return "Heap Sort"; }

REGISTER_ALGORITHM("heap-sort", HeapSort)
