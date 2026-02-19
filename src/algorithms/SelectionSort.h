#ifndef SELECTION_SORT_H_
#define SELECTION_SORT_H_

#include "SortingStrategy.h"

class SelectionSort : public SortingStrategy {
protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

#endif // SELECTION_SORT_H_
