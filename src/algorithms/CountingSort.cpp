#include "CountingSort.h"
#include "SortingAlgorithmRegistry.h"

void CountingSort::sortImp(int arr[], int n) {
  int maxElement = arr[0];
  for (int i = 1; ++count_compare && i < n; i++) {
    if (++count_compare && arr[i] > maxElement)
      maxElement = arr[i];
  }

  int *cnt = new int[maxElement + 1]();
  int *res = new int[n]();

  for (int i = 0; ++count_compare && i < n; i++)
    cnt[arr[i]]++;

  for (int i = 1; ++count_compare && i < maxElement + 1; i++)
    cnt[i] += cnt[i - 1];

  for (int i = n - 1; ++count_compare && i >= 0; i--) {
    res[cnt[arr[i]] - 1] = arr[i];
    cnt[arr[i]]--;
  }

  for (int i = 0; ++count_compare && i < n; i++)
    arr[i] = res[i];

  delete[] cnt;
  delete[] res;
}

std::string CountingSort::getName() const { return "Counting Sort"; }

REGISTER_ALGORITHM("counting-sort", CountingSort)
