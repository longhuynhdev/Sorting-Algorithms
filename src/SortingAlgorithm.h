#ifndef SORTING_ALGORITHM_H_
#define SORTING_ALGORITHM_H_

#include "SortingStrategy.h"
#include <string>

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

// Heap sort
class HeapSort : public SortingStrategy {
private:
  void heapify(int arr[], int n, int i);

protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

// Shaker sort
class ShakerSort : public SortingStrategy {
protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

// Counting sort
class CountingSort : public SortingStrategy {
protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

// Radix sort
class RadixSort : public SortingStrategy {
protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};


// Flash Sort
class FlashSort : public SortingStrategy {
private:
    void flashInsertionSort(int arr[], int s, int e);

protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

// Shell Sort
class ShellSort : public SortingStrategy {
protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

#endif // SORTING_ALGORITHM_H_
