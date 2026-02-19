#ifndef FILE_HANDLER_H_
#define FILE_HANDLER_H_

#include <string>

class FileHandler {
public:
  static int *readArrayFromFile(const std::string &fileName, int &n);
  static void writeArraytoFile(const std::string &fileName, const int arr[],
                               int n);
};

#endif // FILE_HANDLER_H_
