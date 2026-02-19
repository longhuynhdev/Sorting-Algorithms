#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_

#include "SortingStrategy.h"

class BubbleSort : public SortingStrategy {
protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

#endif // BUBBLE_SORT_H_
