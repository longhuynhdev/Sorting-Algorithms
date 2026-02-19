#include "QuickSort.h"
#include "DataGenerator.h"
#include "SortingAlgorithmRegistry.h"

// Partition function with median-of-three pivot selection
int QuickSort::partition(int arr[], int low, int high) {

  int middle = low + (high - low) / 2;

  if (++count_compare && arr[low] > arr[middle]) {
    HoanVi(arr[low], arr[middle]);
  }

  if (++count_compare && arr[low] > arr[high]) {
    HoanVi(arr[low], arr[high]);
  }

  if (++count_compare && arr[middle] > arr[high]) {
    HoanVi(arr[middle], arr[high]);
  }

  HoanVi(arr[middle], arr[high]);

  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; ++count_compare && j < high; j++) {
    if (++count_compare && arr[j] <= pivot) {
      i++;
      HoanVi(arr[i], arr[j]);
    }
  }
  HoanVi(arr[i + 1], arr[high]);
  return (i + 1);
}

// Recursive QuickSort implementation
void QuickSort::quickSort(int arr[], int low, int high) {
  if (++count_compare && low < high) {
    // pi is partitioning index
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void QuickSort::sortImp(int arr[], int n) { quickSort(arr, 0, n - 1); }

std::string QuickSort::getName() const { return "Quick Sort"; }

REGISTER_ALGORITHM("quick-sort", QuickSort)
