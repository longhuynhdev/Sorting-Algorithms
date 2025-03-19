#include "SortingAlgorithm.h"
#include "DataGenerator.h"

void InsertionSort::sortImp(int arr[], int n) {
  for (int i = 1; ++count_compare && i < n; i++) {

    int key = arr[i];
    int j = i - 1;

    while (++count_compare && j >= 0 && ++count_compare && key < arr[j]) {
      arr[j + 1] = arr[j];
      --j;
    }

    arr[j + 1] = key;
  }
}

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

int QuickSort::partition(int arr[], int low, int high) {
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

void SelectionSort::sortImp(int arr[], int n) {
  // TODO: YOUR CODE HERE
}

void BubbleSort::sortImp(int arr[], int n) {
  // TODO: YOUR CODE HERE
}

void MergeSort::sortImp(int arr[], int n) {
  // TODO: YOUR CODE HERE
}

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

void ShakerSort::sortImp(int arr[], int n) {
  int i;
  int k = 0;
  int left = 0;
  int right = n - 1;

  while (++count_compare && left < right) {
    for (int i = left; ++count_compare && i < right; i++) {
      if (++count_compare && arr[i] > arr[i + 1]) {
        HoanVi(arr[i], arr[i + 1]);
        k = i;
      }
    }
    right = k;

    for (int i = right; ++count_compare && i > left; i--) {
      if (++count_compare && arr[i] < arr[i - 1]) {
        HoanVi(arr[i], arr[i - 1]);
        k = i;
      }
    }
    left = k;
  }
}

void CountingSort ::sortImp(int arr[], int n) {
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

void RadixSort ::sortImp(int arr[], int n) {
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

void FlashSort::sortImp(int arr[], int n) {
  int m = 0.005 * n;
  if (m <= 0)
    m = 1;

  int *M = new int[n]();

  int min = arr[0], maxId = 0;
  for (int i = 0; ++count_compare && i < n; i++) {
    if (++count_compare && arr[i] < min)
      min = arr[i];
    if (++count_compare && arr[i] > arr[maxId])
      maxId = i;
  }

  if (++count_compare && arr[maxId] == min)
    return;

  for (int i = 0; ++count_compare && i < n; i++) {
    int k = (m - 1) * (arr[i] - min) / (arr[maxId] - min);
    M[k]++;
  }

  for (int i = 1; ++count_compare && i < m; i++) {
    M[i] += M[i - 1];
  }

  int b[n];
  for (int i = n - 1; ++count_compare && i >= 0; i--) {
    int k = (m - 1) * (arr[i] - min) / (arr[maxId] - min);
    b[--M[k]] = arr[i];
  }

  for (int i = 0; ++count_compare && i < n; i++) {
    arr[i] = b[i];
  }

  int s = 0;
  for (int i = 0; ++count_compare && i < m - 1; i++) {
    flashInsertionSort(arr, s, M[i]);
    s = M[i];
  }
  delete[] M;
}

void FlashSort::flashInsertionSort(int arr[], int s, int e) {
  for (int i = s; ++count_compare && i < e - 1; ++i) {
    int pos = i;
    for (int j = i + 1; ++count_compare && j < e; ++j) {
      if (++count_compare && arr[j] < arr[pos]) {
        pos = j;
      }
    }
    HoanVi(arr[i], arr[pos]);
  }
}

std::string SelectionSort::getName() const { return "Selection Sort"; }
std::string InsertionSort::getName() const { return "Insertion Sort"; }
std::string BinaryInsertionSort::getName() const {
  return "Binary Insertion Sort";
}
std::string QuickSort::getName() const { return "Quick Sort"; }
std::string BubbleSort::getName() const { return "Bubble Sort"; }
std::string MergeSort::getName() const { return "Merge Sort"; }
std::string HeapSort::getName() const { return "Heap Sort"; }
std::string ShakerSort::getName() const { return "Shaker Sort"; }
std::string CountingSort::getName() const { return "Counting Sort"; }
std::string RadixSort::getName() const { return "Radix Sort"; }
std::string FlashSort::getName() const { return "Flash Sort"; }
std::string ShellSort::getName() const { return "Shell Sort"; }
