#ifndef SHELL_SORT_H_
#define SHELL_SORT_H_

#include "SortingStrategy.h"

class ShellSort : public SortingStrategy {
protected:
  void sortImp(int arr[], int n) override;

public:
  std::string getName() const override;
};

#endif // SHELL_SORT_H_
