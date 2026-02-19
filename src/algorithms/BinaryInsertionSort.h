#ifndef BINARY_INSERTION_SORT_H_
#define BINARY_INSERTION_SORT_H_

#include "SortingStrategy.h"

class BinaryInsertionSort : public SortingStrategy {
private:
  int binarySearch(int arr[], int low, int high, int item);

protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

#endif // BINARY_INSERTION_SORT_H_
