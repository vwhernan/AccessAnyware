using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public static class ArrayAlgorithms
    {
        // ========================== INSERTION SORT =============================================
        public static void InsertionSort(int[] arrayToSort)
        {
            if (arrayToSort == null) return;
            int arrSize = arrayToSort.Length;

            for (int i = 1; i < arrSize; ++i)
            {
                int currentValue = arrayToSort[i];
                int j = i - 1;

                while (j >= 0 && arrayToSort[j] > currentValue)
                {
                    arrayToSort[j + 1] = arrayToSort[j];
                    j = j - 1;
                }
                arrayToSort[j + 1] = currentValue;
            }
        }

        // ========================== QUICK SORT =============================================
        private static void Swap(int[] arr, int i, int j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        private static int Partition(int[] arrayToSort, int low, int high)
        {
            int pivot = arrayToSort[high];
            int i = (low - 1);

            for (int j = low; j <= high - 1; j++)
            {
                if (arrayToSort[j] < pivot)
                {
                    i++;
                    Swap(arrayToSort, i, j);
                }
            }

            Swap(arrayToSort, i + 1, high);
            return (i + 1);
        }

        private static void QuickSortRecursive(int[] arrayToSort, int low, int high)
        {
            if (low < high)
            {
                int pi = Partition(arrayToSort, low, high);
                QuickSortRecursive(arrayToSort, low, pi - 1);
                QuickSortRecursive(arrayToSort, pi + 1, high);
            }
        }

        public static void QuickSort(int[] arrayToSort)
        {
            if (arrayToSort == null || arrayToSort.Length <= 1)
            {
                return;
            }
            QuickSortRecursive(arrayToSort, 0, arrayToSort.Length - 1);
        }


        // ========================== MERGE SORT ================================================
        private static void Merge(int[] arrayToSort, int left, int mid, int right)
        {
            int i = 0;
            int leftSize = mid - left + 1;
            int rightSize = right - mid;


            int[] leftArr = new int[leftSize];
            int[] rightArr = new int[rightSize];


            for (i = 0; i < leftSize; i++)
            {
                leftArr[i] = arrayToSort[left + i];
            }
            for (i = 0; i < rightSize; i++)
            {
                rightArr[i] = arrayToSort[mid + 1 + i];
            }

            i = 0;
            int j = 0;
            int k = left;

            while (i < leftSize && j < rightSize)
            {
                if (leftArr[i] <= rightArr[j])
                {
                    arrayToSort[k] = leftArr[i];
                    i++;
                }
                else
                {
                    arrayToSort[k] = rightArr[j];
                    j++;
                }
                k++;
            }

            while (i < leftSize)
            {
                arrayToSort[k] = leftArr[i];
                i++;
                k++;
            }

            while (j < rightSize)
            {
                arrayToSort[k] = rightArr[j];
                j++;
                k++;
            }

        }

        private static void MergeSortRecursive(int[] arrayToSort, int left, int right)
        {
            if (left >= right)
            {
                return;
            }

            int mid = left + (right - left) / 2;

            MergeSortRecursive(arrayToSort, left, mid);
            MergeSortRecursive(arrayToSort, mid + 1, right);

            Merge(arrayToSort, left, mid, right);
        }

        public static void RunMergeSort(int[] arrayToSort)
        {
            if (arrayToSort == null) return;
            MergeSortRecursive(arrayToSort, 0, arrayToSort.Length - 1);
        }

    }
}
