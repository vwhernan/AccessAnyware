using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public class MakeArray
    {
        private int[]? arrInt;
        private int arrSize;
        private static readonly Random random = new Random();

        public MakeArray(int size){
            arrSize = size;
            if (arrSize <= 0)
            {
                Console.Error.WriteLine("Error: Array size must be positive.");
                arrInt = null;
                arrSize = 0; 
            }
            else
            {
                CreateAndFillArray();
            }
        }
        public void CreateAndFillArray(){
          
            arrInt = new int[arrSize];

            for (int i = 0; i < arrSize; i++)
            {
                arrInt[i] = random.Next(arrSize);
            }
        }

        //Getters
        public int GetSize() => arrSize;
        public int[] GetArrInt() => arrInt;

       //funcitons
        public void PrintArray(){
            if (arrInt == null || arrSize == 0)
            {
                Console.WriteLine("Array is empty or invalid.");
                return;
            }

            Console.WriteLine($"Array [{arrSize}]: {{{string.Join(", ", arrInt)}}}");
        }
        
  
    }
}
