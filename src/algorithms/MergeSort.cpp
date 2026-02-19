#include "MergeSort.h"
#include "SortingAlgorithmRegistry.h"

void MergeSort::merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int *L = new int[n1];
  int *R = new int[n2];

  for (int i = 0; ++count_compare && i < n1; i++) {
    L[i] = arr[left + i];
  }

  for (int j = 0; ++count_compare && j < n2; j++) {
    R[j] = arr[mid + 1 + j];
  }

  int i = 0, j = 0, k = left;

  while (++count_compare && i < n1 && ++count_compare && j < n2) {
    if (++count_compare && L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (++count_compare && i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (++count_compare && j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }

  delete[] L;
  delete[] R;
}

void MergeSort::mergeSort(int arr[], int left, int right) {
  if (++count_compare && left < right) {
    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
  }
}

void MergeSort::sortImp(int arr[], int n) { mergeSort(arr, 0, n - 1); }

std::string MergeSort::getName() const { return "Merge Sort"; }

REGISTER_ALGORITHM("merge-sort", MergeSort)
