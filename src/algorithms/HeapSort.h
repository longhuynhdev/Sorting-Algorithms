#ifndef HEAP_SORT_H_
#define HEAP_SORT_H_

#include "SortingStrategy.h"

class HeapSort : public SortingStrategy {
private:
  void heapify(int arr[], int n, int i);

protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

#endif // HEAP_SORT_H_
