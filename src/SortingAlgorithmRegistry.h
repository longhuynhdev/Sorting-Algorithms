#ifndef SORTING_ALGORITHM_REGISTRY_H_
#define SORTING_ALGORITHM_REGISTRY_H_

#include "SortingStrategy.h"
#include <functional>
#include <map>
#include <string>

class SortingAlgorithmRegistry {
public:
  using FactoryFunction = std::function<SortingStrategy *()>;

  static SortingAlgorithmRegistry &instance();

  void registerAlgorithm(const std::string &name, FactoryFunction factory);
  SortingStrategy *create(const std::string &name) const;

private:
  SortingAlgorithmRegistry() = default;
  std::map<std::string, FactoryFunction> registry_;
};

// Macro for self-registration in each algorithm's .cpp file
#define REGISTER_ALGORITHM(cli_name, ClassName)                                \
  namespace {                                                                  \
  static bool _registered_##ClassName = [] {                                   \
    SortingAlgorithmRegistry::instance().registerAlgorithm(                     \
        cli_name, [] { return new ClassName(); });                             \
    return true;                                                               \
  }();                                                                         \
  }

#endif // SORTING_ALGORITHM_REGISTRY_H_
