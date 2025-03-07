#include "SortingAlgorithm.h"

#include <cstring>
#include <string>
#include <iostream>
#include <fstream>

void printArray(int array[], int n)
{
  for (int i = 0; i < n; i++)
  {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

void handleArguments(int argc, char *argv[])
{
  if (argc < 2)
  {
    exit(1);
  }
  // Mode -a Algorithm mode
  if (strcmp(argv[1], "-a") == 0)
  {
    if (argc == 5)
    {
      // Command 1 Ex: a.exe -a radix-sort input.txt -both
      if (strstr(argv[3], ".txt") != NULL)
      {
        std::string inputFileName = argv[3];
        std::string outputFileName = "output.txt";
      }
      // Command 3 Ex: a.exe -a binary-insertion-sort 70000 -comp
      else if (atoi(argv[3]) > 0)
      {
        std::cout << "Command 3" << std::endl;
      }
    }
    else if (argc == 6)
    {
      // Command 2 Ex: a.exe -a selection-sort 50 -rand -time
      std::cout << "Command 2" << std::endl;
    }
  }
  // Mode -c Compare mode
  else if (strcmp(argv[1], "-c") == 0)
  {
    if (argc == 5)
    {
      // Command 4: Ex: a.exe -c heap-sort merge-sort input.txt
      std::cout << "Command 4" << std::endl;
    }
    else if (argc == 6)
    {
      // Command 5: Ex: a.exe -c quick-sort merge-sort 100000 -nsorted
      std::cout << "Command 5" << std::endl;
    }
  }
}

int main(int argc, char *argv[])
{
  handleArguments(argc, argv);
  return 0;
}