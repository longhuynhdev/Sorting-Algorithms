#include "FlashSort.h"
#include "SortingAlgorithmRegistry.h"

void FlashSort::sortImp(int arr[], int n) {
  if (++count_compare && n <= 1) {
    return;
  }

  // Determine number of buckets (m)
  int m = static_cast<int>(0.005 * n);

  if (++count_compare && m <= 0)
    m = 1;

  // Allocate bucket array M, initialized to 0
  int *M = new int[m]();

  // Step 1: Find minimum and maximum values
  int min = arr[0], maxId = 0;
  for (int i = 0; ++count_compare && i < n; i++) {
    if (++count_compare && arr[i] < min)
      min = arr[i];
    if (++count_compare && arr[i] > arr[maxId])
      maxId = i;
  }

  // Early exit if all elements are equal
  if (++count_compare && arr[maxId] == min) {
    delete[] M;
    return;
  }

  // Step 2: Assign elements to buckets
  for (int i = 0; ++count_compare && i < n; i++) {
    int k = static_cast<int>((m - 1.0) * (arr[i] - min) / (arr[maxId] - min));
    M[k]++;
  }

  // Step 3: Compute cumulative sum for bucket boundaries
  for (int i = 1; ++count_compare && i < m; i++) {
    M[i] += M[i - 1];
  }

  // Step 4: Permutation using a temporary array
  int *b = new int[n];
  for (int i = n - 1; ++count_compare && i >= 0; i--) {
    int k = static_cast<int>((m - 1.0) * (arr[i] - min) / (arr[maxId] - min));
    b[--M[k]] = arr[i];
  }

  // Step 5: Copy permuted array back to original array
  for (int i = 0; ++count_compare && i < n; i++) {
    arr[i] = b[i];
  }

  // Step 6: Sort each bucket using insertion sort
  int s = 0;
  for (int i = 0; ++count_compare && i < m; i++) {
    int e = (++count_compare && i == m - 1) ? n : M[i];
    flashInsertionSort(arr, s, e);
    s = e;
  }

  // Clean up dynamically allocated memory
  delete[] M;
  delete[] b;
}

void FlashSort::flashInsertionSort(int arr[], int s, int e) {
  for (int i = s + 1; ++count_compare && i < e; i++) {
    int key = arr[i];
    int j = i - 1;
    while (++count_compare && j >= s && ++count_compare && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

std::string FlashSort::getName() const { return "Flash Sort"; }

REGISTER_ALGORITHM("flash-sort", FlashSort)
