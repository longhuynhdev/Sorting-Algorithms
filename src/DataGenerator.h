#ifndef DATA_GENERATOR_H
#define DATA_GENERATOR_H

#include <fstream>
#include <cmath>
#include <time.h>

template <class T>
void HoanVi(T &a, T &b);
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

#endif // DATA_GENERATOR_H