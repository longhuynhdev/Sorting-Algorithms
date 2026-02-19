#include "ShellSort.h"
#include "SortingAlgorithmRegistry.h"

void ShellSort::sortImp(int arr[], int n) {
  for (int interval = n / 2; ++count_compare && interval > 0; interval /= 2) {
    for (int i = interval; ++count_compare && i < n; i++) {
      int temp = arr[i];
      int j;
      for (j = i; (++count_compare && j >= interval) &&
                  (++count_compare && arr[j - interval] > temp);
           j -= interval) {
        arr[j] = arr[j - interval];
      }
      arr[j] = temp;
    }
  }
}

std::string ShellSort::getName() const { return "Shell Sort"; }

REGISTER_ALGORITHM("shell-sort", ShellSort)
