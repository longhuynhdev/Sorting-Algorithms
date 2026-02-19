#ifndef RADIX_SORT_H_
#define RADIX_SORT_H_

#include "SortingStrategy.h"

class RadixSort : public SortingStrategy {
protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

#endif // RADIX_SORT_H_
