#include "DataGenerator.h"
#include "FileHandler.h"
#include "OutputFormatter.h"
#include "SortingAlgorithmRegistry.h"
#include "SortingStrategy.h"
#include <chrono>
#include <cstring>
#include <iostream>
#include <string>

using std::chrono::duration;

void showUsage(const char *programName) {
  std::cout << "Usage:" << std::endl;
  std::cout << "  Algorithm mode:" << std::endl;
  std::cout << "    " << programName
            << " -a <algorithm> <input-file> <output-param>" << std::endl;
  std::cout << "    " << programName
            << " -a <algorithm> <size> <input-order> [output-param]"
            << std::endl;
  std::cout << "    " << programName
            << " -a <algorithm> <size> [output-param]" << std::endl;
  std::cout << std::endl;
  std::cout << "  Compare mode:" << std::endl;
  std::cout << "    " << programName
            << " -c <algorithm1> <algorithm2> <input-file>" << std::endl;
  std::cout << "    " << programName
            << " -c <algorithm1> <algorithm2> <size> <input-order>"
            << std::endl;
  std::cout << std::endl;
  std::cout << "Algorithms:" << std::endl;
  std::cout << "  selection-sort, insertion-sort, binary-insertion-sort,"
            << std::endl;
  std::cout << "  bubble-sort, shaker-sort, shell-sort, heap-sort,"
            << std::endl;
  std::cout << "  merge-sort, quick-sort, counting-sort, radix-sort,"
            << std::endl;
  std::cout << "  flash-sort" << std::endl;
  std::cout << std::endl;
  std::cout << "Input orders:    -rand, -sorted, -nsorted, -rev" << std::endl;
  std::cout << "Output params:   -time, -comp, -both" << std::endl;
}

int *generateArray(int n, const std::string &pattern) {
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
    std::cout << "Error: Unknown data pattern: " << pattern << std::endl;
    delete[] arr;
    return nullptr;
  }

  return arr;
}

// references:
// https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
double runAlgorithm(SortingStrategy *algorithm, int arr[], int n) {
  auto start = std::chrono::high_resolution_clock::now();
  algorithm->sort(arr, n);
  auto end = std::chrono::high_resolution_clock::now();

  duration<double, std::milli> executionTime = end - start;
  return executionTime.count();
}

void compareAlgorithms(SortingStrategy *algo1, SortingStrategy *algo2,
                       int arr[], int n, double &time1, double &time2) {

  int *arr1 = new int[n];
  int *arr2 = new int[n];

  std::copy(arr, arr + n, arr1);
  std::copy(arr, arr + n, arr2);

  // Run first algorithm
  time1 = runAlgorithm(algo1, arr1, n);
  // Run second algorithm
  time2 = runAlgorithm(algo2, arr2, n);

  delete[] arr1;
  delete[] arr2;
}

// Command 1
void handleCommand1(const std::string &algo, const std::string &given_input,
                    const std::string &output_parameter = "") {
  std::string filename_out = "output.txt";
  SortingStrategy *sort_method =
      SortingAlgorithmRegistry::instance().create(algo);
  if (!sort_method) {
    std::cout << "Error: Invalid algorithm name(s)" << std::endl;
    return;
  }

  int n;
  int *arr = FileHandler::readArrayFromFile(given_input, n);
  double runtime = runAlgorithm(sort_method, arr, n);

  std::cout << "Algorithm: " << sort_method->getName() << std::endl;
  std::cout << "Input file: " << given_input << std::endl;
  std::cout << "Input size: " << n << std::endl;
  std::cout << "-------------------------------------" << std::endl;

  OutputFormatter::printOutputParameter(
      output_parameter, sort_method->getCountCompare(), runtime);
  FileHandler::writeArraytoFile(filename_out, arr, n);
  delete[] arr;
  delete sort_method;
}

// Command 2
void handleCommand2(const std::string &algo, int n,
                    const std::string &input_order,
                    const std::string &output_parameter = "") {
  std::string filename_in = "input.txt";
  std::string filename_out = "output.txt";
  SortingStrategy *sort_method =
      SortingAlgorithmRegistry::instance().create(algo);
  if (!sort_method) {
    std::cout << "Error: Invalid algorithm name(s)" << std::endl;
    return;
  }

  std::cout << "Algorithm: " << sort_method->getName() << std::endl;
  std::cout << "Input size: " << n << std::endl;
  std::cout << "Input order: " << OutputFormatter::parameter2Order(input_order)
            << std::endl;
  std::cout << "-------------------------------------" << std::endl;

  int *arr = generateArray(n, input_order);
  FileHandler::writeArraytoFile(filename_in, arr, n);
  double runtime = runAlgorithm(sort_method, arr, n);
  FileHandler::writeArraytoFile(filename_out, arr, n);
  OutputFormatter::printOutputParameter(
      output_parameter, sort_method->getCountCompare(), runtime);

  delete[] arr;
  delete sort_method;
}

// Command 3
void handleCommand3(const std::string &algo, int n,
                    const std::string &output_parameter = "") {
  std::string sort_types[4] = {"Randomize", "Nearly Sorted", "Sorted",
                                "Reversed"};
  std::string filename_out = "output.txt";
  SortingStrategy *sort_method =
      SortingAlgorithmRegistry::instance().create(algo);
  if (!sort_method) {
    std::cout << "Error: Invalid algorithm name(s)" << std::endl;
    return;
  }

  std::cout << "Algorithm: " << sort_method->getName() << std::endl;
  std::cout << "Input size: " << n << std::endl << std::endl;

  int *arr = new int[n];
  for (int i = 0; i < 4; i++) {
    std::string filename_in = "input_" + std::to_string(i + 1) + ".txt";
    GenerateData(arr, n, i);
    FileHandler::writeArraytoFile(filename_in, arr, n);
    double runtime = runAlgorithm(sort_method, arr, n);
    std::cout << "Input order: " << sort_types[i] << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    OutputFormatter::printOutputParameter(
        output_parameter, sort_method->getCountCompare(), runtime);
    std::cout << std::endl;
  }

  delete[] arr;
  delete sort_method;
}

// Command 4
// [Algorithm 1] [Algorithm 2] [Given input]
void handleCommand4(const std::string &algo1, const std::string &algo2,
                    const std::string &fileName) {
  SortingStrategy *sorter1 =
      SortingAlgorithmRegistry::instance().create(algo1);
  SortingStrategy *sorter2 =
      SortingAlgorithmRegistry::instance().create(algo2);

  if (!sorter1 || !sorter2) {
    std::cout << "Error: Invalid algorithm name(s)" << std::endl;
    delete sorter1;
    delete sorter2;
    return;
  }

  int n = 0;
  int *arr = FileHandler::readArrayFromFile(fileName, n);
  if (arr != nullptr) {
    double time1 = 0;
    double time2 = 0;
    compareAlgorithms(sorter1, sorter2, arr, n, time1, time2);
    OutputFormatter::printComparisonMode(
        sorter1->getName(), time1, sorter1->getCountCompare(),
        sorter2->getName(), time2, sorter2->getCountCompare(), fileName, n);
  }

  delete[] arr;
  delete sorter1;
  delete sorter2;
}

// [Algorithm 1] [Algorithm 2] [Input size] [Input order]
void handleCommand5(const std::string &algo1, const std::string &algo2,
                    int inputSize, const std::string &inputOrder) {
  SortingStrategy *sorter1 =
      SortingAlgorithmRegistry::instance().create(algo1);
  SortingStrategy *sorter2 =
      SortingAlgorithmRegistry::instance().create(algo2);

  if (!sorter1 || !sorter2) {
    std::cout << "Error: Invalid algorithm name(s)" << std::endl;
    delete sorter1;
    delete sorter2;
    return;
  }

  if (inputSize <= 0 || inputSize > 1000000) {
    std::cout << "Error: Input size must be between 1 and 1,000,000"
              << std::endl;
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

  double time1 = 0;
  double time2 = 0;
  compareAlgorithms(sorter1, sorter2, arr, inputSize, time1, time2);

  OutputFormatter::printComparisonMode(
      sorter1->getName(), time1, sorter1->getCountCompare(), sorter2->getName(),
      time2, sorter2->getCountCompare(), "", inputSize, inputOrder);
  std::string fileName = "input.txt";
  FileHandler::writeArraytoFile(fileName, arr, inputSize);

  delete[] arr;
  delete sorter1;
  delete sorter2;
}

void handleArguments(int argc, char *argv[]) {
  if (argc < 2) {
    showUsage(argv[0]);
    exit(1);
  }
  // Mode -a Algorithm mode
  if (strcmp(argv[1], "-a") == 0) {
    if (argc < 4) {
      showUsage(argv[0]);
      exit(1);
    }
    std::cout << "ALGORITHM MODE" << std::endl;
    if (argc == 4) {
      // Command 3 Ex: a.exe -a binary-insertion-sort 70000
      if (atoi(argv[3]) > 0) {
        handleCommand3(argv[2], atoi(argv[3]));
      } else {
        showUsage(argv[0]);
        exit(1);
      }
    } else if (argc == 5) {
      // Command 1 Ex: a.exe -a radix-sort input.txt -both
      if (strstr(argv[3], ".txt") != NULL) {
        handleCommand1(argv[2], argv[3], argv[4]);
      }
      // Command 3 Ex: a.exe -a binary-insertion-sort 70000 -comp
      else if (atoi(argv[3]) > 0 &&
               (std::string(argv[4]) == "-time" ||
                std::string(argv[4]) == "-comp" ||
                std::string(argv[4]) == "-both")) {
        handleCommand3(argv[2], atoi(argv[3]), argv[4]);
      }
      // Command 2 Ex: a.exe -a selection-sort 50 -rand
      else {
        handleCommand2(argv[2], atoi(argv[3]), argv[4]);
      }
    } else if (argc == 6) {
      // Command 2 Ex: a.exe -a selection-sort 50 -rand -time
      handleCommand2(argv[2], atoi(argv[3]), argv[4], argv[5]);
    } else {
      showUsage(argv[0]);
      exit(1);
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
    } else {
      showUsage(argv[0]);
      exit(1);
    }
  } else {
    showUsage(argv[0]);
    exit(1);
  }
}

int main(int argc, char *argv[]) {
  handleArguments(argc, argv);
  return 0;
}
