#ifndef SORTING_ALGORITHM_H_
#define SORTING_ALGORITHM_H_

#include "SortingStrategy.h"

class InsertionSort : public SortingStrategy {
protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

class QuickSort : public SortingStrategy {
private:
  int partition(int arr[], int low, int high);
  void quickSort(int arr[], int low, int high);

protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

class BinaryInsertionSort : public SortingStrategy {
private:
  int binarySearch(int arr[], int low, int high, int item);

protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

class SelectionSort : public SortingStrategy {
protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

class BubbleSort : public SortingStrategy {
protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

class MergeSort : public SortingStrategy {
protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

#endif // SORTING_ALGORITHM_H_