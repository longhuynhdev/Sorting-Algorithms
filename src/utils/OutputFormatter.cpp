#include "OutputFormatter.h"
#include <iostream>

void OutputFormatter::printArray(int array[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

void OutputFormatter::printOutputParameter(const std::string &parameter,
                                           long long count_compare,
                                           double runtime) {
  if (parameter == "-time") {
    std::cout << "Running time: " << runtime << " (ms)" << std::endl;
  } else if (parameter == "-comp") {
    std::cout << "Comparisions: " << count_compare << std::endl;
  } else if (parameter == "-both") {
    std::cout << "Running time: " << runtime << " (ms)" << std::endl;
    std::cout << "Comparisions: " << count_compare << std::endl;
  }
}

void OutputFormatter::printComparisonMode(
    const std::string &algoName1, double time1, long long comp1,
    const std::string &algoName2, double time2, long long comp2,
    const std::string &fileName, int n, const std::string &inputOrder) {
  std::cout << "COMPARE MODE" << std::endl;
  std::cout << "Algorithm: " << algoName1 << " | " << algoName2 << std::endl;
  if (!fileName.empty()) {
    std::cout << "Input file: " << fileName << std::endl;
    std::cout << "Input size: " << n << std::endl;
  } else if (!inputOrder.empty()) {
    std::cout << "Input size: " << n << std::endl;
    std::cout << "Input order: " << inputOrder << std::endl;
  }
  std::cout << "-------------------------------------" << std::endl;
  std::cout << "Running time: " << time1 << "(ms)"
            << " | " << time2 << "(ms)" << std::endl;
  std::cout << "Comparisons: " << comp1 << " | " << comp2 << std::endl;
  std::cout << std::endl;
}

std::string OutputFormatter::parameter2Order(const std::string &parameter) {
  std::string order_name = "";
  if (parameter == "-rand") {
    order_name = "Randomize";
  } else if (parameter == "-sorted") {
    order_name = "Sorted";
  } else if (parameter == "-nsorted") {
    order_name = "Nearly Sorted";
  } else if (parameter == "-rev") {
    order_name = "Reversed";
  } else {
    std::cout << "Error: Invalid input order";
  }

  return order_name;
}
