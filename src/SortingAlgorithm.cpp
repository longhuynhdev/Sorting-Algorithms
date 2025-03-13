#include "SortingAlgorithm.h"

void InsertionSort::sortImp(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    count_compare++; // Count comparison in for loop (i < n)

    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && key < arr[j]) {
      count_compare += 2; // Count comparison j >= 0 and key < arr[j]
      arr[j + 1] = arr[j];
      --j;
    }

    count_compare += (j >= 0) ? 2 : 1;

    arr[j + 1] = key;
  }
}

int BinaryInsertionSort::binarySearch(int arr[], int low, int high, int item) {
  while (low <= high) {
    count_compare++; // Count comparison low <= high
    int mid = low + (high - low) / 2;

    count_compare++; // Count comparison item == arr[mid]
    if (item == arr[mid]) {
      return mid;
    }

    count_compare++; // Count comparison item > arr[mid]
    if (item > arr[mid]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return low; // Return insertion position
}

void BinaryInsertionSort::sortImp(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    count_compare++; // Count comparison in for loop (i < n)

    int key = arr[i];
    int j = i - 1;

    // Find location to insert using binary search
    int location = binarySearch(arr, 0, j, key);

    while (j >= location) {
      count_compare++; // Count comparison j >= location
      arr[j + 1] = arr[j];
      j--;
    }
    count_compare++; // Count for last comparison when j < location

    arr[j + 1] = key;
  }
}

int QuickSort::partition(int arr[], int low, int high) {
  int pivot = arr[high];

  int i = low - 1;

  for (int j = low; j < high; j++) {
    count_compare++; // Count comparison in for loop (j < high)
    count_compare++; // Count comparison arr[j] <= pivot
    if (arr[j] <= pivot) {
      i++;
      HoanVi(arr[i], arr[j]);
    }
  }
  HoanVi(arr[i + 1], arr[high]);
  return (i + 1);
}

// Recursive QuickSort implementation
void QuickSort::quickSort(int arr[], int low, int high) {
  count_compare++; // Count comparison low < high
  if (low < high) {
    // pi is partitioning index
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void QuickSort::sortImp(int arr[], int n) { quickSort(arr, 0, n - 1); }

void SelectionSort::sortImp(int arr[], int n) {
  // TODO: YOUR CODE HERE
}

void BubbleSort::sortImp(int arr[], int n) {
  // TODO: YOUR CODE HERE
}

void MergeSort::sortImp(int arr[], int n) {
  // TODO: YOUR CODE HERE
}

std::string SelectionSort::getName() const { return "Selection Sort"; }
std::string InsertionSort::getName() const { return "Insertion Sort"; }
std::string BinaryInsertionSort::getName() const {
  return "Binary Insertion Sort";
}
std::string QuickSort::getName() const { return "Quick Sort"; }
std::string BubbleSort::getName() const { return "Bubble Sort"; }
std::string MergeSort::getName() const { return "Merge Sort"; }