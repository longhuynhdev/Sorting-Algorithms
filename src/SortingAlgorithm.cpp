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
          cnt[(arr[i] / exp) % 10]++;

      for(int i = 1; ++count_compare && i < 10; i++)
          cnt[i] += cnt[i - 1];

      for(int i = n - 1; ++count_compare && i >= 0; i--){
          res[cnt[(arr[i] / exp) % 10] - 1] = arr[i];
          cnt[(arr[i] / exp) % 10]--;
      }

      for(int i = 0; ++count_compare && i < n; i++)
          arr[i] = res[i];     
      
  }
  delete[] res;
   
}
//SHELL SORT

void shellSort_Time(int array[], int n, double& t) {
	auto start = chrono::high_resolution_clock::now();
	for (int interval = n / 2; interval > 0; interval /= 2)
	{
		for (int i = interval; i < n; i += 1)
		{
			int temp = array[i];
			int j;
			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = temp;
		}
	}
	auto end = chrono::high_resolution_clock::now();
	t = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void shellSort_Compare(int array[], int n, long long& cmp) {
	for (int interval = n / 2; ++cmp && interval > 0; interval /= 2) {
		for (int i = interval; ++cmp && i < n; i += 1) {
			int temp = array[i];
			int j;
			for (j = i; ++cmp && j >= interval && ++cmp && array[j - interval] > temp; j -= interval) {
				array[j] = array[j - interval];
			}
			array[j] = temp;
		}
	}
}

//FLASH SORT

void flashInsertionSort_Time(int* a, int s, int e) {
	for (int i = s; i < e - 1; ++i) {
		int pos = i;
		for (int j = i + 1; j < e; ++j) {
			if ((a[j] < a[pos])) {
				pos = j;
			}
		}
		swap(a[i], a[pos]);
	}
}

void flashSort_Time(int* a, int size, double& t) {
	auto start = chrono::high_resolution_clock::now();
	int m = 0.005 * size;
	int* M = new int[m];
	int* _M = new int[m];
	for (int i = 0; i < m; i++) {
		M[i] = 0;
	}

	int min = a[0], maxId = 0;
	for (int i = 0; i < size; i++) {
		if (a[i] < min)
			min = a[i];
		if (a[i] > a[maxId])
			maxId = i;
	}

	for (int i = 0; i < size; i++) {
		int k = (m - 1) * (a[i] - min) / (a[maxId] - min);
		M[k]++;
	}
	for (int i = 0; i < m - 1; i++) {
		M[i + 1] = M[i] + M[i + 1];
		_M[i] = M[i];
	}
	_M[m - 1] = M[m - 1];

	int* b = new int[size];
	for (int i = 0; i < size; i++) {
		int k = (m - 1) * (a[i] - min) / (a[maxId] - min);
		b[--M[k]] = a[i];
	}

	for (int i = 0; i < size; i++)
		a[i] = b[i];
	delete[] b;

	int cnt = 0;
	int s = 0;
	while (cnt < m - 1) {
		flashInsertionSort_Time(a, s, _M[cnt]);
		s = _M[cnt];
		cnt++;
	}
	delete[] M;
	delete[] _M;
	auto end = chrono::high_resolution_clock::now();
	t = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void flashInsertionSort_Compare(int* a, int s, int e, long long& cmp) {
	for (int i = s; ++cmp && i < e - 1; ++i) {
		int pos = i;
		for (int j = i + 1; ++cmp && j < e; ++j) {
			if (++cmp && (a[j] < a[pos])) {
				pos = j;
			}
		}
		swap(a[i], a[pos]);
	}
}

void flashSort_Compare(int* a, int size, long long& cmp) {
	int m = 0.005 * size;
	int* M = new int[m];
	int* _M = new int[m];
	for (int i = 0; ++cmp && i < m; i++) {
		_M[i] = 0;
		M[i] = 0;
	}

	int min = a[0], maxId = 0;
	for (int i = 0; ++cmp && i < size; i++) {
		if (++cmp && (a[i] < min))
			min = a[i];
		if (++cmp && (a[i] > a[maxId]))
			maxId = i;
	}

	for (int i = 0; ++cmp && i < size; i++) {
		int k = (m - 1) * (a[i] - min) / (a[maxId] - min);
		M[k]++;
	}
	for (int i = 0; ++cmp && i < m - 1; i++) {
		M[i + 1] = M[i] + M[i + 1];
		_M[i] = M[i];
	}
	_M[m - 1] = M[m - 1];

	int* b = new int[size];
	for (int i = 0; ++cmp && i < size; i++) {
		int k = (m - 1) * (a[i] - min) / (a[maxId] - min);
		b[--M[k]] = a[i];
	}

	for (int i = 0; ++cmp && i < size; i++)
		a[i] = b[i];
	delete[] b;

	int cnt = 0;
	int s = 0;
	while (++cmp && (cnt < m - 1)) {
		flashInsertionSort_Compare(a, s, M[cnt], cmp);
		s = M[cnt];
		cnt++;
	}
	delete[] M;
}

void flashSort(int a[], int size, double& t, long long& cmp, int output, string data_file) {
	if (output == 1)
		flashSort_Time(a, size, t);
	else if (output == 2)
		flashSort_Compare(a, size, cmp);
	else if (output == 3) {
		flashSort_Time(a, size, t);
		readFile(data_file, a, size);
		flashSort_Compare(a, size, cmp);
	}
}

void shellSort(int a[], int size, double& t, long long& cmp, int output, string data_file) {
	if (output == 1) {
		shellSort_Time(a, size, t);
	}
	else if (output == 2) {
		shellSort_Compare(a, size, cmp);
	}
	else if (output == 3) {
		shellSort_Time(a, size, t);
		readFile(data_file, a, size);
		shellSort_Compare(a, size, cmp);
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
std::string CountingSort::getName() const { return "Counting Sort";}
std::string RadixSort::getName() const {return "Radix Sort";}
std::string flashSort::getName() const { return "Flash Sort";}
std::string shellSort::getName() const {return "Shell Sort";}
