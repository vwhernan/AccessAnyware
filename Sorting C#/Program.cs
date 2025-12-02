

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Merge Test------------------------------------------------------------------------------");
            MakeArray testArr = new MakeArray(20);
            Console.Write("Unsorted: ");
            testArr.PrintArray();
            ArrayAlgorithms.RunMergeSort(testArr.GetArrInt());
            Console.Write("Sorted: ");
            testArr.PrintArray();
            Console.WriteLine("-----------------------------------------------------------------------------------------");

            Console.WriteLine("\nSelection Test-------------------------------------------------------------------------");
            testArr = new MakeArray(20);
            Console.Write("Unsorted: ");
            testArr.PrintArray();
            ArrayAlgorithms.InsertionSort(testArr.GetArrInt());
            Console.Write("Sorted: ");
            testArr.PrintArray();
            Console.WriteLine("-----------------------------------------------------------------------------------------");

            Console.WriteLine("\nQuick Test-----------------------------------------------------------------------------");
            testArr = new MakeArray(20);
            Console.Write("Unsorted: ");
            testArr.PrintArray();
            ArrayAlgorithms.QuickSort(testArr.GetArrInt());
            Console.Write("Sorted: ");
            testArr.PrintArray();
            Console.WriteLine("-----------------------------------------------------------------------------------------");
        }
    }
}
