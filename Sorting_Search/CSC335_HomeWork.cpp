using namespace std;
#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <list>
#include "CSC335_HomeWork.h"

const int ARRAY_1000 = 1000;
const int ARRAY_10000 = 10000;
const int ARRAY_50000 = 50000;
const int ARRAY_100000 = 100000;
const int ARRAY_150000 = 150000;
const int ARRAY_200000 = 200000;
const int ARRAY_250000 = 250000;
const int ARRAY_300000 = 300000;


    MakeArray::MakeArray(int size) : arrInt(nullptr), arrSize(size) {
        if (arrSize <= 0) {
            std::cerr << "Error: Array size must be positive." << std::endl;
            arrInt = nullptr;
            return;
        }

        createAndFillArray();
    }
    MakeArray::~MakeArray() {
        {
            delete[] arrInt;
            arrInt = nullptr;
        }
    }
    void MakeArray::createAndFillArray() {
        arrInt = new int[arrSize];

        static bool seeded = false;
        if (!seeded)
        {
            srand(static_cast<unsigned int>(time(nullptr)));
            seeded = true;
        }

        for (int i = 0; i < arrSize; i++)
        {
            arrInt[i] = rand() % arrSize;
        }
    }
    void MakeArray::printArray() {
        if (arrInt == nullptr) {
            std::cout << "Array is empty or invalid." << std::endl;
            return;
        }
        std::cout << "Array [" << arrSize << "]: {";
        for (int i = 0; i < arrSize; i++) {
            std::cout << arrInt[i] << (i == arrSize - 1 ? "" : ", ");
        }
        std::cout << "}" << std::endl;
    }





//SORTING FUNCTIONS
    
//==========================INSERTION SORT=============================================
    void InsertionSort(int* arrayToSort, int arrSize) {
        // 
        for (int i = 1; i < arrSize; ++i) {
            
            int current_value = arrayToSort[i];
            int j = i - 1;

           
            while (j >= 0 && arrayToSort[j] > current_value) {
                arrayToSort[j + 1] = arrayToSort[j];
                j = j - 1;
            }

  
            arrayToSort[j + 1] = current_value;
        }
    }
  

//==========================QUICK SORT=============================================
    void Swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int Partition(int* arrayToSort, int low, int high) {

        int pivot = arrayToSort[high];


        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {

            if (arrayToSort[j] < pivot) {
                i++;
                Swap(&arrayToSort[i], &arrayToSort[j]);
            }
        }

        Swap(&arrayToSort[i + 1], &arrayToSort[high]);
        return (i + 1);
    }
    
    void QuickSortRecursive(int* arrayToSort, int low, int high) {
        if (low < high) {
            int pi = Partition(arrayToSort, low, high);

            QuickSortRecursive(arrayToSort, low, pi - 1);
            QuickSortRecursive(arrayToSort, pi + 1, high);
        }
    }

    void QuickSort(int* arrayToSort, int arrSize) {
        if (arrayToSort == NULL || arrSize <= 1) {
            return; 
        }
        QuickSortRecursive(arrayToSort, 0, arrSize - 1);
    }

   

   


//==========================MERGE SORT================================================
void Merge(int* arrayToSort, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];

    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arrayToSort[left + i];
    for (int i = 0; i < rightSize; i++)
        rightArr[i] = arrayToSort[mid + 1 + i];

   
    int i = 0; 
    int j = 0; 
    int k = left; 

    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arrayToSort[k] = leftArr[i];
            i++;
        }
        else {
            arrayToSort[k] = rightArr[j];
            j++;
        }
        k++;
    }


    while (i < leftSize) {
        arrayToSort[k] = leftArr[i];
        i++;
        k++;
    }


    while (j < rightSize) {
        arrayToSort[k] = rightArr[j];
        j++;
        k++;
    }

 
    delete[] leftArr;
    delete[] rightArr;
}

void MergeSort(int* arrayToSort, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    MergeSort(arrayToSort, left, mid);

    MergeSort(arrayToSort, mid + 1, right);

    Merge(arrayToSort, left, mid, right);
}

void RunMergeSort(int* arrayToSort, int arrSize) {
    MergeSort(arrayToSort, 0, arrSize - 1);
}




//RECURSIVE FUNCTIONS
int RecursiveAddIntegers(int n) {
    
    if (n < 0) {
     cout <<("Input 'n' must be a non-negative integer.");
    }

    
    if (n == 0) {
        return 0;
    }


    return n + RecursiveAddIntegers(n - 1);
}



//TESTERS
void RecursiveFunctionTest()
{
    int n = 2;
    
    //should return 3
    int sum = RecursiveAddIntegers(n);
    cout << "The sum when n = " << n << " is: " << sum << endl;
    
    sum = 0;
    n = 10; 

    //should return 55
    sum = RecursiveAddIntegers(n);
    cout << "The sum when n = " << n << " is: " << sum << endl;

    sum = 0;
    n = 15;

    //should return 120
    sum = RecursiveAddIntegers(n);
    cout << "The sum when n = " << n << " is: " << sum << endl;
    
}

void InsertionSortTest() {
    vector<string> labels = {"20", "1000", "10000", "50000", "100000", "150000", "200000", "250000", "300000"};
    vector<double> times;



    //20 Test -- Show output for this test to show sort is working
    cout << "\--------------------------------------" << endl;
    cout << "20 TEST" << endl;
    MakeArray aM = MakeArray(20);

    auto start0 = chrono::high_resolution_clock::now();
    InsertionSort(aM.getArrInt(), aM.getSize());
    auto end0 = chrono::high_resolution_clock::now();

    double t0 = chrono::duration<double>(end0 - start0).count();
    times.push_back(t0);

    aM.printArray();
    aM.~MakeArray();
    cout << "\n--------------------------------------" << endl;
    
    //1000 Test 
    cout << "1000 TEST" << endl;
    MakeArray aM1 = MakeArray(ARRAY_1000);

    auto start1 = chrono::high_resolution_clock::now();
    InsertionSort(aM1.getArrInt(), aM1.getSize());
    auto end1 = chrono::high_resolution_clock::now();

    double t1 = chrono::duration<double>(end1 - start1).count();
    times.push_back(t1);
    aM1.~MakeArray();
 
    cout << "Complete"<< endl;
    cout << "--------------------------------------" << endl;

    //10000 Test
    cout << "10000 TEST-" << endl;
    MakeArray aM2 = MakeArray(ARRAY_10000);

    auto start2 = chrono::high_resolution_clock::now();
    InsertionSort(aM2.getArrInt(), aM2.getSize());
    auto end2 = chrono::high_resolution_clock::now();

    double t2 = chrono::duration<double>(end2 - start2).count();
    times.push_back(t2);
    aM2.~MakeArray();
    
    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;


    //50000
    cout << "50000 TEST" << endl;
    MakeArray aM3 = MakeArray(ARRAY_50000);

    auto start3 = chrono::high_resolution_clock::now();
    InsertionSort(aM3.getArrInt(), aM3.getSize());
    auto end3 = chrono::high_resolution_clock::now();

    double t3 = chrono::duration<double>(end3 - start3).count();
    times.push_back(t3);

    aM3.~MakeArray();
    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;

    //100000
    cout << "100000 TEST" << endl;
    MakeArray aMOops = MakeArray(ARRAY_100000);

    auto startOops = chrono::high_resolution_clock::now();
    InsertionSort(aMOops.getArrInt(), aMOops.getSize());
    auto endOops = chrono::high_resolution_clock::now();

    double tOops = chrono::duration<double>(endOops - startOops).count();
    times.push_back(tOops);

    aMOops.~MakeArray();
    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;

    //150000
    cout << "150000 TEST" << endl;
    MakeArray aM4 = MakeArray(ARRAY_150000);

    auto start4 = chrono::high_resolution_clock::now();
    InsertionSort(aM4.getArrInt(), aM4.getSize());
    auto end4 = chrono::high_resolution_clock::now();

    double t4 = chrono::duration<double>(end4 - start4).count();
    times.push_back(t4);
    aM4.~MakeArray();
    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;


    //200000
    cout << "200000 TEST" << endl;
    MakeArray aM5 = MakeArray(ARRAY_200000);

    auto start5 = chrono::high_resolution_clock::now();
    InsertionSort(aM5.getArrInt(), aM5.getSize());
    auto end5 = chrono::high_resolution_clock::now();

    double t5 = chrono::duration<double>(end5 - start5).count();
    times.push_back(t5);
    aM5.~MakeArray();
    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;


    //250000
    cout << "250000 TEST" << endl;
    MakeArray aM6 = MakeArray(ARRAY_250000);

    auto start6 = chrono::high_resolution_clock::now();
    InsertionSort(aM6.getArrInt(), aM6.getSize());
    auto end6 = chrono::high_resolution_clock::now();

    double t6 = chrono::duration<double>(end6 - start6).count();
    times.push_back(t6);
    aM6.~MakeArray();
    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;


    //300000
    cout << "300000 TEST" << endl;
    MakeArray aM7 = MakeArray(ARRAY_300000);

    auto start7 = chrono::high_resolution_clock::now();
    InsertionSort(aM7.getArrInt(), aM7.getSize());
    auto end7 = chrono::high_resolution_clock::now();

    double t7 = chrono::duration<double>(end7 - start7).count();
    times.push_back(t7);
    aM7.~MakeArray();
    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;
    

    cout << "\n===== INSERTION SORT TIME SUMMARY =====\n";
    for (size_t i = 0; i < times.size(); i++) {
        cout << labels[i] << " TEST: " << times[i] << " seconds\n";
    }

}

void MergeSortTest() {   
    vector<string> labels = { "20", "1000", "10000", "50000", "100000", "150000", "200000", "250000", "300000" };
    vector<double> times;

    //20 Test -- Show output for this test to show sort is working
    cout << "--------------------------------------" << endl;
    cout << "20 TEST" << endl;
    MakeArray aM = MakeArray(20);

    auto start0 = chrono::high_resolution_clock::now();
    RunMergeSort(aM.getArrInt(), aM.getSize());
    auto end0 = chrono::high_resolution_clock::now();

    double t0 = chrono::duration<double>(end0 - start0).count();
    times.push_back(t0);
    aM.printArray();
    aM.~MakeArray();
    cout << "\n--------------------------------------" << endl;

    //1000 Test 
    cout << "1000 TEST" << endl;
    MakeArray aM1 = MakeArray(ARRAY_1000);

    auto start1 = chrono::high_resolution_clock::now();
    RunMergeSort(aM1.getArrInt(), aM1.getSize());
    auto end1 = chrono::high_resolution_clock::now();

    double t1 = chrono::duration<double>(end1 - start1).count();
    times.push_back(t1);
    aM1.~MakeArray();

    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;

    //10000 Test
    cout << "10000 TEST-" << endl;
    MakeArray aM2 = MakeArray(ARRAY_10000);

    auto start2 = chrono::high_resolution_clock::now();
    RunMergeSort(aM2.getArrInt(), aM2.getSize());
    auto end2 = chrono::high_resolution_clock::now();

    double t2 = chrono::duration<double>(end2 - start2).count();
    times.push_back(t2);
    aM2.~MakeArray();

    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;


    //50000
    cout << "50000 TEST" << endl;
    MakeArray aM3 = MakeArray(ARRAY_50000);

    auto start3 = chrono::high_resolution_clock::now();
    RunMergeSort(aM3.getArrInt(), aM3.getSize());
    auto end3 = chrono::high_resolution_clock::now();

    double t3 = chrono::duration<double>(end3 - start3).count();
    times.push_back(t3);

    aM3.~MakeArray();
    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;

    //100000
    cout << "100000 TEST" << endl;
    MakeArray aM4 = MakeArray(ARRAY_100000);

    auto start4 = chrono::high_resolution_clock::now();
    RunMergeSort(aM4.getArrInt(), aM4.getSize());
    auto end4 = chrono::high_resolution_clock::now();

    double t4 = chrono::duration<double>(end4 - start4).count();
    times.push_back(t4);

    aM4.~MakeArray();
    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;

    //150000
    cout << "150000 TEST" << endl;
    MakeArray aM5 = MakeArray(ARRAY_150000);

    auto start5 = chrono::high_resolution_clock::now();
    RunMergeSort(aM5.getArrInt(), aM5.getSize());
    auto end5 = chrono::high_resolution_clock::now();

    double t5 = chrono::duration<double>(end5 - start5).count();
    times.push_back(t5);
    aM4.~MakeArray();
    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;


    //200000
    cout << "200000 TEST" << endl;
    MakeArray aM6 = MakeArray(ARRAY_200000);

    auto start6 = chrono::high_resolution_clock::now();
    RunMergeSort(aM6.getArrInt(), aM6.getSize());
    auto end6 = chrono::high_resolution_clock::now();

    double t6 = chrono::duration<double>(end6 - start6).count();
    times.push_back(t6);
    aM6.~MakeArray();
    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;


    //250000
    cout << "250000 TEST" << endl;
    MakeArray aM7 = MakeArray(ARRAY_250000);

    auto start7 = chrono::high_resolution_clock::now();
    RunMergeSort(aM7.getArrInt(), aM7.getSize());
    auto end7 = chrono::high_resolution_clock::now();

    double t7 = chrono::duration<double>(end7 - start7).count();
    times.push_back(t7);
    aM7.~MakeArray();
    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;


    //300000
    cout << "300000 TEST" << endl;
    MakeArray aM8 = MakeArray(ARRAY_300000);

    auto start8 = chrono::high_resolution_clock::now();
    RunMergeSort(aM8.getArrInt(), aM8.getSize());
    auto end8 = chrono::high_resolution_clock::now();

    double t8 = chrono::duration<double>(end8 - start8).count();
    times.push_back(t8);
    aM8.~MakeArray();
    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;


    cout << "\n===== MERGE SORT TIME SUMMARY =====\n";
    for (size_t i = 0; i < times.size(); i++) {
        cout << labels[i] << " TEST: " << times[i] << " seconds\n";
    }



}

void QuickSortTest() {
    vector<string> labels = { "20", "1000", "10000", "50000", "100000", "150000", "200000", "250000", "300000" };
    vector<double> times;

    //20 Test -- Show output for this test to show sort is working
    cout << "--------------------------------------" << endl;
    cout << "20 TEST" << endl;
    MakeArray aM = MakeArray(20);

    auto start0 = chrono::high_resolution_clock::now();
    QuickSort(aM.getArrInt(), aM.getSize());
    auto end0 = chrono::high_resolution_clock::now();

    double t0 = chrono::duration<double>(end0 - start0).count();
    times.push_back(t0);
    aM.printArray();
    aM.~MakeArray();
    cout << "\n--------------------------------------" << endl;

    //1000 Test 
    cout << "1000 TEST" << endl;
    MakeArray aM1 = MakeArray(ARRAY_1000);
    
    auto start1 = chrono::high_resolution_clock::now();
    QuickSort(aM1.getArrInt(), aM1.getSize());
    auto end1 = chrono::high_resolution_clock::now();

    double t1 = chrono::duration<double>(end1 - start1).count();
    times.push_back(t1);
    aM1.printArray();
    aM1.~MakeArray();

    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;

    //10000 Test
    cout << "10000 TEST" << endl;
    MakeArray aM2 = MakeArray(ARRAY_10000);

    auto start2 = chrono::high_resolution_clock::now();
    QuickSort(aM2.getArrInt(), aM2.getSize());
    auto end2 = chrono::high_resolution_clock::now();

    double t2 = chrono::duration<double>(end2 - start2).count();
    times.push_back(t2);
    aM2.~MakeArray();

    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;


    //50000
    cout << "50000 TEST" << endl;
    MakeArray aM3 = MakeArray(ARRAY_50000);

    auto start3 = chrono::high_resolution_clock::now();
    QuickSort(aM3.getArrInt(), aM3.getSize());
    auto end3 = chrono::high_resolution_clock::now();

    double t3 = chrono::duration<double>(end3 - start3).count();
    times.push_back(t3);

    aM3.~MakeArray();
    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;

    //100000
    cout << "100000 TEST" << endl;
    MakeArray aM4 = MakeArray(ARRAY_100000);

    auto start4 = chrono::high_resolution_clock::now();
    QuickSort(aM4.getArrInt(), aM4.getSize());
    auto end4 = chrono::high_resolution_clock::now();

    double t4 = chrono::duration<double>(end4 - start4).count();
    times.push_back(t4);

    aM4.~MakeArray();
    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;

    //150000
    cout << "150000 TEST" << endl;
    MakeArray aM5 = MakeArray(ARRAY_150000);

    auto start5 = chrono::high_resolution_clock::now();
    QuickSort(aM5.getArrInt(), aM5.getSize());
    auto end5 = chrono::high_resolution_clock::now();

    double t5 = chrono::duration<double>(end5 - start5).count();
    times.push_back(t5);
    aM4.~MakeArray();
    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;


    //200000
    cout << "200000 TEST" << endl;
    MakeArray aM6 = MakeArray(ARRAY_200000);

    auto start6 = chrono::high_resolution_clock::now();
    QuickSort(aM6.getArrInt(), aM6.getSize());
    auto end6 = chrono::high_resolution_clock::now();

    double t6 = chrono::duration<double>(end6 - start6).count();
    times.push_back(t6);
    aM6.~MakeArray();
    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;


    //250000
    cout << "250000 TEST" << endl;
    MakeArray aM7 = MakeArray(ARRAY_250000);

    auto start7 = chrono::high_resolution_clock::now();
    QuickSort(aM7.getArrInt(), aM7.getSize());
    auto end7 = chrono::high_resolution_clock::now();

    double t7 = chrono::duration<double>(end7 - start7).count();
    times.push_back(t7);
    aM7.~MakeArray();
    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;


    //300000
    cout << "300000 TEST" << endl;
    MakeArray aM8 = MakeArray(ARRAY_300000);

    auto start8 = chrono::high_resolution_clock::now();
    QuickSort(aM8.getArrInt(), aM8.getSize());
    auto end8 = chrono::high_resolution_clock::now();

    double t8 = chrono::duration<double>(end8 - start8).count();
    times.push_back(t8);
    aM8.~MakeArray();
    cout << "Complete" << endl;
    cout << "--------------------------------------" << endl;


    cout << "\n===== MERGE SORT TIME SUMMARY =====\n";
    for (size_t i = 0; i < times.size(); i++) {
        cout << labels[i] << " TEST: " << times[i] << " seconds\n";
    }



}

