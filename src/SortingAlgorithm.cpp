#include "SortingAlgorithm.h"

void InsertionSort::sortImp(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    count_compare++; // Count in for loop (i < n)

    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && key < arr[j]) {
      count_compare += 2; // Count j >= 0 and key < arr[j]
      arr[j + 1] = arr[j];
      --j;
    }

    count_compare += (j >= 0) ? 2 : 1;

    arr[j + 1] = key;
  }
}

std::string InsertionSort::getName() const { return "Insertion Sort"; }

int QuickSort::partition(int arr[], int low, int high) {
  int pivot = arr[high];

  int i = low - 1;

  for (int j = low; j < high; j++) {
    count_compare++; // Count in for loop (j < high)

    count_compare++; // Count arr[j] <= pivot
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

std::string QuickSort::getName() const { return "Quick Sort"; }

void SelectionSort::sortImp(int arr[], int n) {
  // TODO: YOUR CODE HERE
}

std::string SelectionSort::getName() const { return "Selection Sort"; }

void BubbleSort::sortImp(int arr[], int n) {
  //TODO: YOUR CODE HERE
}

std::string BubbleSort::getName() const { return "Bubble Sort"; }

void MergeSort::sortImp(int arr[], int n) {
  // TODO: YOUR CODE HERE
}

std::string MergeSort::getName() const { return "Merge Sort"; }