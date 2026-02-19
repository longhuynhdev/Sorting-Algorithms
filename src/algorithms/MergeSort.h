#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

#include "SortingStrategy.h"

class MergeSort : public SortingStrategy {
private:
  void merge(int arr[], int left, int mid, int right);
  void mergeSort(int arr[], int left, int right);

protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

#endif // MERGE_SORT_H_
