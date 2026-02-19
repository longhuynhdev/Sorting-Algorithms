#include "FileHandler.h"
#include <fstream>
#include <iostream>

int *FileHandler::readArrayFromFile(const std::string &fileName, int &n) {
  std::ifstream myFile;
  myFile.open(fileName);
  if (!myFile.is_open()) {
    std::cout << "Error: Unable to open file " << fileName << std::endl;
    n = 0;
    return nullptr;
  }

  myFile >> n;

  if (n <= 0) {
    std::cout << "Error: Invalid array size in file" << std::endl;
    n = 0;
    return nullptr;
  }

  int *arr = new int[n];

  for (int i = 0; i < n; i++) {
    myFile >> arr[i];
  }

  myFile.close();
  return arr;
}

void FileHandler::writeArraytoFile(const std::string &fileName,
                                   const int arr[], int n) {
  std::ofstream myFile;
  myFile.open(fileName);
  if (!myFile.is_open()) {
    std::cout << "Error: Unable to open file: " << fileName << std::endl;
    return;
  }

  myFile << n << std::endl;
  for (int i = 0; i < n; i++) {
    myFile << arr[i] << " ";
  }

  myFile.close();
}
