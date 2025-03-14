#include "DataGenerator.h"
#include "SortingAlgorithm.h"
#include "SortingStrategy.h"
#include <chrono>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void printArray(int array[], int n) {
  for (int i = 0; i < n; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

int *readArrayFromFile(string fileName, int &n) {
  ifstream myFile;
  myFile.open(fileName);
  if (!myFile.is_open()) {
    cout << "Error: Unable to open file " << fileName << endl;
    n = 0;
    return nullptr;
  }

  myFile >> n;

  if (n <= 0) {
    cout << "Error: Invalid array size in file" << endl;
    n = 0;
    return nullptr;
  }

  int *arr = new int[n];

  for (int i = 0; i < n; i++) {
    myFile >> arr[i];
  }

  myFile.close();
  return arr;
}

void writeArraytoFile(string fileName, const int arr[], int n) {
  ofstream myFile;
  myFile.open(fileName);
  if (!myFile.is_open()) {
    cout << "Error: Unable to open file: " << fileName << endl;
    return;
  }

  myFile << n << endl;
  for (int i = 0; i < n; i++) {
    myFile << arr[i] << " ";
  }

  myFile.close();
}

int *generateArray(int n, string pattern) {
  int *arr = new int[n];

  if (pattern == "-rand") {
    GenerateData(arr, n, 0);
  } else if (pattern == "-sorted") {
    GenerateData(arr, n, 2);
  } else if (pattern == "-rev") {
    GenerateData(arr, n, 3);
  } else if (pattern == "-nsorted") {
    GenerateData(arr, n, 1);
  } else {
    cout << "Error: Unknown data pattern: " << pattern << endl;
    delete[] arr;
    return nullptr;
  }

  return arr;
}

// references:
// https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
long long runAlgorithm(SortingStrategy *algorithm, int arr[], int n) {
  auto start = chrono::high_resolution_clock::now();
  algorithm->sort(arr, n);
  auto end = chrono::high_resolution_clock::now();

  long long executionTime =
      chrono::duration_cast<chrono::milliseconds>(end - start).count();
  return executionTime;
}

void compareAlgorithms(SortingStrategy *algo1, SortingStrategy *algo2,
                       int arr[], int n, long long &time1, long long &time2) {

  int *arr1 = new int[n];
  int *arr2 = new int[n];

  copy(arr, arr + n, arr1);
  copy(arr, arr + n, arr2);

  // Run first algorithm
  time1 = runAlgorithm(algo1, arr1, n);
  // Run second algorithm
  time2 = runAlgorithm(algo2, arr2, n);

  delete[] arr1;
  delete[] arr2;
}

void printOutputParameter(string parameter, long long count_compare, long long runtime) {
  if (parameter == "-time") {
    cout << "Running time: " << runtime << " (ms)" << endl;
  } else if (parameter == "-comp") {
    cout << "Comparisions: " << count_compare << endl;
  } else if (parameter == "-both") {
    cout << "Running time: " << runtime << " (ms)" << endl;
    cout << "Comparisions: " << count_compare << endl;
  }
}

void printComparisonMode(string algoName1, long long time1, long long comp1,
                         string algoName2, long long time2, long long comp2,
                         string fileName = "", int n = 0,
                         string inputOrder = "") {
  cout << "COMPARE MODE" << endl;
  cout << "Algorithm: " << algoName1 << " | " << algoName2 << endl;
  if (!fileName.empty()) {
    cout << "Input file: " << fileName << endl;
    cout << "Input size: " << n << endl;
  } else if (!inputOrder.empty()) {
    cout << "Input size: " << n << endl;
    cout << "Input order: " << inputOrder << endl;
  }
  cout << "-------------------------------------" << endl;
  cout << "Running time: " << time1 << "(ms)"
       << " | " << time2 << "(ms)" << endl;
  cout << "Comparisons: " << comp1 << " | " << comp2 << endl;
  cout << endl;
}

SortingStrategy *createSortingAlgorithm(const string &name) {
  if (name == "selection-sort")
    return new SelectionSort();
  if (name == "insertion-sort")
    return new InsertionSort();
  if (name == "binary-insertion-sort")
    return new BinaryInsertionSort();
  if (name == "bubble-sort")
    return new BubbleSort();
  if (name == "shaker-sort")
    return new ShakerSort();
  // if (name == "shell-sort") return new ShellSort();
  if (name == "heap-sort")
    return new HeapSort();
  if (name == "merge-sort")
    return new MergeSort();
  if (name == "quick-sort")
    return new QuickSort();
  // if (name == "counting-sort") return new CountingSort();
  // if (name == "radix-sort") return new RadixSort();
  // if (name == "flash-sort") return new FlashSort();

  cout << "Unknown sorting algorithm: " << name << endl;
  return nullptr;
}

string parameter2Order(string parameter) {
  string order_name = "";
  if (parameter == "-rand") {
    order_name = "Randomize";
  } else if (parameter == "-sorted") {
    order_name = "Sorted";
  } else if (parameter == "-nsorted") {
    order_name = "Nearly Sorted";
  } else if (parameter == "-rev") {
    order_name = "Reversed";
  } else {
    cout << "Error: Invalid input order";
  }

  return order_name;
}

// Command 2
void handleCommand2(string algo, int n, string input_order,
                    string output_parameter = "") {
  string filename_in = "input/input.txt";
  string filename_out = "input/output.txt";
  SortingStrategy *sort_method = createSortingAlgorithm(algo);
  cout << "Algorithm: " << sort_method->getName() << endl;
  cout << "Input size: " << n << endl;
  cout << "Input order: " << parameter2Order(input_order) << endl;
  cout << "-------------------------------------" << endl;
  if (!sort_method) {
    cout << "Error: Invalid algorithm name(s)" << endl;
    delete sort_method;
    return;
  }

  int *arr = generateArray(n, input_order);
  writeArraytoFile(filename_in, arr, n);
  long long runtime = runAlgorithm(sort_method, arr, n);
  printOutputParameter(output_parameter, sort_method->getCountCompare(),
                       runtime);

  delete[] arr;
  delete sort_method;
}

// Command 3
void handleCommand3(string algo, int n, string output_parameter = "") {
  string sort_types[4] = {"Randomize", "Nearly Sorted", "Sorted", "Reversed"};
  string filename_out = "input/output.txt";
  SortingStrategy *sort_method = createSortingAlgorithm(algo);
  cout << "Algorithm: " << sort_method->getName() << endl;
  cout << "Input size: " << n << endl << endl;

  int *arr = new int[n];
  for (int i = 0; i < 4; i++) {
    string filename_in = "input/input_" + to_string(i + 1) + ".txt";
    GenerateData(arr, n, i);
    writeArraytoFile(filename_in, arr, n);
    long long runtime = runAlgorithm(sort_method, arr, n);
    cout << "Input order: " << sort_types[i] << endl;
    cout << "-------------------------------------" << endl;
    printOutputParameter(output_parameter, sort_method->getCountCompare(),
                         runtime);
    cout << endl;
  }

  if (!sort_method) {
    cout << "Error: Invalid algorithm name(s)" << endl;
    delete sort_method;
    return;
  }

  delete[] arr;
  delete sort_method;
}

// Command 4
// [Algorithm 1] [Algorithm 2] [Given input]
void handleCommand4(string algo1, string algo2, string fileName) {
  SortingStrategy *sorter1 = createSortingAlgorithm(algo1);
  SortingStrategy *sorter2 = createSortingAlgorithm(algo2);

  if (!sorter1 || !sorter2) {
    cout << "Error: Invalid algorithm name(s)" << endl;
    delete sorter1;
    delete sorter2;
    return;
  }

  int n = 0;
  int *arr = readArrayFromFile(fileName, n);
  if (arr != nullptr) {
    long long time1 = 0;
    long long comp1 = 0;
    long long time2 = 0;
    long long comp2 = 0;
    compareAlgorithms(sorter1, sorter2, arr, n, time1, time2);
    printComparisonMode(sorter1->getName(), time1, sorter1->getCountCompare(),
                        sorter2->getName(), time2, sorter2->getCountCompare(),
                        fileName, n);
  }

  delete[] arr;
  delete sorter1;
  delete sorter2;
}

// [Algorithm 1] [Algorithm 2] [Input size] [Input order]
void handleCommand5(string algo1, string algo2, int inputSize,
                    string inputOrder) {
  SortingStrategy *sorter1 = createSortingAlgorithm(algo1);
  SortingStrategy *sorter2 = createSortingAlgorithm(algo2);

  if (!sorter1 || !sorter2) {
    cout << "Error: Invalid algorithm name(s)" << endl;
    delete sorter1;
    delete sorter2;
    return;
  }

  if (inputSize <= 0 || inputSize > 1000000) {
    cout << "Error: Input size must be between 1 and 1,000,000" << endl;
    delete sorter1;
    delete sorter2;
    return;
  }

  int *arr = generateArray(inputSize, inputOrder);

  if (arr == nullptr) {
    delete sorter1;
    delete sorter2;
    return;
  }

  long long time1 = 0;
  long long time2 = 0;
  compareAlgorithms(sorter1, sorter2, arr, inputSize, time1, time2);

  printComparisonMode(sorter1->getName(), time1, sorter1->getCountCompare(),
                      sorter2->getName(), time2, sorter2->getCountCompare(), "",
                      inputSize, inputOrder);
  string fileName = "input.txt";
  writeArraytoFile(fileName, arr, inputSize);

  delete[] arr;
  delete sorter1;
  delete sorter2;
}

void handleArguments(int argc, char *argv[]) {
  if (argc < 2) {
    exit(1);
  }
  // Mode -a Algorithm mode
  if (strcmp(argv[1], "-a") == 0) {
    cout << "ALGORITHM MODE" << endl;
    if (argc == 4) {
      // Command 3 Ex: a.exe -a binary-insertion-sort 70000
      if (atoi(argv[3]) > 0) {
        handleCommand3(argv[2], atoi(argv[3]));
      }
    } else if (argc == 5) {
      // Command 1 Ex: a.exe -a radix-sort input.txt -both
      if (strstr(argv[3], ".txt") != NULL) {
        string inputFileName = argv[3];
        string outputFileName = "output.txt";
      }
      // Command 3 Ex: a.exe -a binary-insertion-sort 70000 -comp
      else if (atoi(argv[3]) > 0 &&
               (string(argv[4]) == "-time" || string(argv[4]) == "-comp" ||
                string(argv[4]) == "-both")) {
        handleCommand3(argv[2], atoi(argv[3]), argv[4]);
      }
      // Command 2 Ex: a.exe -a selection-sort 50 -rand
      else {
        handleCommand2(argv[2], atoi(argv[3]), argv[4]);
      }
    } else if (argc == 6) {
      // Command 2 Ex: a.exe -a selection-sort 50 -rand -time
      handleCommand2(argv[2], atoi(argv[3]), argv[4], argv[5]);
    }
  }
  // Mode -c Compare mode
  else if (strcmp(argv[1], "-c") == 0) {
    if (argc == 5) {
      // Command 4: Ex: a.exe -c heap-sort merge-sort input.txt
      handleCommand4(argv[2], argv[3], argv[4]);
    } else if (argc == 6) {
      // Command 5: Ex: a.exe -c quick-sort merge-sort 100000 -nsorted
      int inputSize = atoi(argv[4]);
      handleCommand5(argv[2], argv[3], inputSize, argv[5]);
    }
  }
}

int main(int argc, char *argv[]) {
  handleArguments(argc, argv);
  return 0;
}
