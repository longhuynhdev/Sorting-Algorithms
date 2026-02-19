#include "SortingAlgorithmRegistry.h"
#include <iostream>

SortingAlgorithmRegistry &SortingAlgorithmRegistry::instance() {
  static SortingAlgorithmRegistry inst;
  return inst;
}

void SortingAlgorithmRegistry::registerAlgorithm(const std::string &name,
                                                 FactoryFunction factory) {
  registry_[name] = factory;
}

SortingStrategy *
SortingAlgorithmRegistry::create(const std::string &name) const {
  auto it = registry_.find(name);
  if (it == registry_.end()) {
    std::cout << "Unknown sorting algorithm: " << name << std::endl;
    return nullptr;
  }
  return it->second();
}
