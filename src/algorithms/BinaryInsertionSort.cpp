#include "BinaryInsertionSort.h"
#include "SortingAlgorithmRegistry.h"

int BinaryInsertionSort::binarySearch(int arr[], int low, int high, int item) {
  while (++count_compare && low <= high) {
    int mid = low + (high - low) / 2;

    if (++count_compare && item == arr[mid]) {
      return mid;
    }

    if (++count_compare && item > arr[mid]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return low; // Return insertion position
}

void BinaryInsertionSort::sortImp(int arr[], int n) {
  for (int i = 1; ++count_compare && i < n; i++) {

    int key = arr[i];
    int j = i - 1;

    // Find location to insert using binary search
    int location = binarySearch(arr, 0, j, key);

    while (++count_compare && j >= location) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
  }
}

std::string BinaryInsertionSort::getName() const {
  return "Binary Insertion Sort";
}

REGISTER_ALGORITHM("binary-insertion-sort", BinaryInsertionSort)
