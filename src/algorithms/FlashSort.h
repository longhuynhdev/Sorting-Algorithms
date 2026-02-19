#ifndef FLASH_SORT_H_
#define FLASH_SORT_H_

#include "SortingStrategy.h"

class FlashSort : public SortingStrategy {
private:
  void flashInsertionSort(int arr[], int s, int e);

protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

#endif // FLASH_SORT_H_
