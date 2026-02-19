#include "RadixSort.h"
#include "SortingAlgorithmRegistry.h"

void RadixSort::sortImp(int arr[], int n) {
  int maxElement = arr[0];
  for (int i = 1; ++count_compare && i < n; i++) {
    if (++count_compare && arr[i] > maxElement)
      maxElement = arr[i];
  }

  int *res = new int[n];

  for (int exp = 1; ++count_compare && maxElement / exp > 0; exp *= 10) {
    int cnt[10] = {0};

    for (int i = 0; ++count_compare && i < n; i++)
      cnt[(arr[i] / exp) % 10]++;

    for (int i = 1; ++count_compare && i < 10; i++)
      cnt[i] += cnt[i - 1];

    for (int i = n - 1; ++count_compare && i >= 0; i--) {
      res[cnt[(arr[i] / exp) % 10] - 1] = arr[i];
      cnt[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; ++count_compare && i < n; i++)
      arr[i] = res[i];
  }
  delete[] res;
}

std::string RadixSort::getName() const { return "Radix Sort"; }

REGISTER_ALGORITHM("radix-sort", RadixSort)
