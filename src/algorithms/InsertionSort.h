#ifndef INSERTION_SORT_H_
#define INSERTION_SORT_H_

#include "SortingStrategy.h"

class InsertionSort : public SortingStrategy {
protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

#endif // INSERTION_SORT_H_
