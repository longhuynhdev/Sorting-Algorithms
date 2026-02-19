#ifndef COUNTING_SORT_H_
#define COUNTING_SORT_H_

#include "SortingStrategy.h"

class CountingSort : public SortingStrategy {
protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

#endif // COUNTING_SORT_H_
