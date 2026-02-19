#ifndef SHAKER_SORT_H_
#define SHAKER_SORT_H_

#include "SortingStrategy.h"

class ShakerSort : public SortingStrategy {
protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

#endif // SHAKER_SORT_H_
