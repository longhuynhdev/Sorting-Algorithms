#ifndef OUTPUT_FORMATTER_H_
#define OUTPUT_FORMATTER_H_

#include <string>

class OutputFormatter {
public:
  static void printArray(int array[], int n);
  static void printOutputParameter(const std::string &parameter,
                                   long long count_compare, double runtime);
  static void printComparisonMode(const std::string &algoName1, double time1,
                                  long long comp1,
                                  const std::string &algoName2, double time2,
                                  long long comp2,
                                  const std::string &fileName = "", int n = 0,
                                  const std::string &inputOrder = "");
  static std::string parameter2Order(const std::string &parameter);
};

#endif // OUTPUT_FORMATTER_H_
