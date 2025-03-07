#ifndef SORTING_STRATEGY_H_
#define SORTING_STRATEGY_H_

#include "DataGenerator.h"
#include <iostream>
#include <string>

class SortingStrategy
{
protected:
  long long count_compare;
  // Pure virtual method derived classes will implement
  virtual void sortImp(int arr[], int n) = 0;

public:
  SortingStrategy() : count_compare(0) {}
  virtual ~SortingStrategy() = default;

  // Pure virtual method to get the method name
  virtual std::string getName() const = 0;

  // Non-virtual public sort method (Template Method Pattern)
  void sort(int arr[], int n)
  {
    // Reset counters
    count_compare = 0;

    // Call the actual implementation
    sortImp(arr, n);
  }

  // Getters
  long long getCountCompare() const { return count_compare; }
};

#endif // SORTING_STRATEGY_H_