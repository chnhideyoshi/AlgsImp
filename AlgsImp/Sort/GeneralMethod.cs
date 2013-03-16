using System;
using System.Collections.Generic;
using System.Text;

namespace AlgsImp.Sort
{
    public interface ISorter<T>
    {
         T[] A{get;set;}
         void Sort();
    }
    public static class GeneralMethod
    {
        static Random rA = new Random();
        public static void RandomTestManyTimes(int times, ISorter<int> sorter, int capacity)
        {
            for (int i = 0; i < times; i++)
            {
                RandomTest(sorter, capacity);
            }
        }
        public static bool RandomTest(ISorter<int> sorter,int capacity)
        {
            int[] a = new int[capacity];
            for (int i = 0; i < a.Length; i++)
            {
                a[i] = rA.Next(0, 500000);
            }
            sorter.A = a;
            sorter.Sort();
            for (int i = 0; i < a.Length - 1; i++)
            {
                if (a[i] > a[i + 1])
                {
                    Console.WriteLine("failed");
                    return false;
                }
            }
            Console.WriteLine("passed");
            return true;
        }
        public static void Output<T>(T[] A)
        {
            for (int i = 0; i < A.Length; i++)
            {
                if (i != A.Length - 1)
                {
                    Console.Write(A[i] + ",");
                }
                else
                {
                    Console.Write(A[i]);
                }

            }
            Console.WriteLine();
        }
        public static void Swap<T>(T[] A, int index1, int index2)
        {
            T temp = A[index1];
            A[index1] = A[index2];
            A[index2] = temp;
        }
        public static bool CheckSorted<T>(T[] A, int st, int ed) where T:IComparable<T>
        {
            for (int i = st; i <= ed - 1; i++)
            {
                if(A[i].CompareTo(A[i+1])>0)
                {
                    return false;
                }
            }
            return true;
        }
    }
}
