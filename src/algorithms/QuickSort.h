#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

#include "SortingStrategy.h"

class QuickSort : public SortingStrategy {
private:
  int partition(int arr[], int low, int high);
  void quickSort(int arr[], int low, int high);

protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

#endif // QUICK_SORT_H_
