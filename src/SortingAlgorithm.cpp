#include "SortingAlgorithm.h"
#include <utility>

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

// Heap sort
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
    std::swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void HeapSort::sortImp(int arr[], int n) {
  // Build heap
  for (int i = n / 2 - 1; ++count_compare && i >= 0; i--) {
    heapify(arr, n, i);
  }

  for (int i = n - 1; ++count_compare && i >= 0; i--) {
    std::swap(arr[0], arr[i]);
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
        std::swap(arr[i], arr[i + 1]);
        k = i;
      }
    }
    right = k;

    for (int i = right; ++count_compare && i > left; i--) {
      if (++count_compare && arr[i] < arr[i - 1]) {
        std::swap(arr[i], arr[i - 1]);
        k = i;
      }
    }
    left = k;
  }
}




void CountingSort :: sortImp(int arr[], int n){
  int maxElement = arr[0];
  for(int i = 1; ++count_compare && i < n; i++){
    if(arr[i] > maxElement)
      maxElement = arr[i];
  }

  int* cnt = new int[maxElement + 1]{0};
  int* res = new int[n]{0};
  for(int i = 0; ++count_compare && i < n; i++)
    cnt[arr[i]]++;

  for(int i = 1; ++count_compare && i < maxElement + 1; i++)
    cnt[i] += cnt[i - 1];

  for(int i = n - 1; ++count_compare && i >= 0; i--){
    res[cnt[arr[i]] - 1] = arr[i];
    cnt[arr[i]]--; 
  }

  for(int i = 0; ++count_compare && i < n; i++)
    arr[i] = res[i];
  
  delete[] cnt;
  delete[] res;
}

void RadixSort :: sortImp(int arr[], int n){
  int maxElement = arr[0];
  for(int i = 1; ++count_compare && i < n; i++){
    if(arr[i] > maxElement)
      maxElement = arr[i];
  }
  int* res = new int[n];
  for(int exp = 1; ++count_compare && maxElement / exp > 0; exp *= 10){
      int cnt[10]{0};
      for(int i = 0; ++count_compare && i < n; i++)
          cnt[(arr[i]/exp) % 10]++;
      for(int i = 1; ++count_compare && i < 10; i++)
          cnt[i] += cnt[i - 1];
      for(int i = n - 1; ++count_compare && i >= 0; i--){
          res[cnt[(arr[i] / exp) % 10] - 1] = arr[i];
          cnt[(arr[i]/exp) % 10]--;
      }
      for(int i = 0; ++count_compare && i < n; i++)
          arr[i] = res[i];     
      
  }
  delete[] res;
   
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
std::string CountingSort::getName() const { return "Counting Sort";}
std::string RadixSort::getName() const {return "Radix Sort";}
