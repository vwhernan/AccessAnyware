#ifndef CSC335_HOMEWORK_H
#define CSC335_HOMEWORK_H
#include <list>

//classes
class MakeArray {
    int* arrInt;
    int arrSize;
public:
    MakeArray(int size);
    ~MakeArray();
    void createAndFillArray();   
    void printArray();
    int getSize() const { return arrSize; }
    int* getArrInt() const  { return arrInt; };
};

//Methods
void InsertionSort(int* arrayToSort, int size);
void RunMergeSort(int* arrayToSort, int arrSize);
void QuickSort(int* arrayToSort, int arrSize);
int RecursiveAddIntegers(int n);

//Method Tests
void RecursiveFunctionTest();
void InsertionSortTest();
void MergeSortTest();
void QuickSortTest();
#endif