using System;
using System.Collections.Generic;
using System.Text;

namespace AlgsImp.Miscellaneous
{
    public class Arrangement<T>
    {
        T[] Data;
        T[] temp;
        public void SetInput(T[] data)
        {
            this.Data=data;
            temp = new T[Data.Length];
        }
        public static void Swap<T>(T[] A, int index1, int index2)
        {
            T temp = A[index1];
            A[index1] = A[index2];
            A[index2] = temp;
        }
        public void PrintArrangement()
        {
            PrintArrangement(0);
        }   
        private void PrintArrangement(int stindex)
        {
            if (stindex == Data.Length-1 )
            {
                for (int i = 0; i < Data.Length; i++)
                {
                    Console.Write(Data[i]);
                }
                Console.Write("\n");
            }
            else
            {
                for (int i = stindex; i < Data.Length; i++)
                {
                    Swap<T>(Data, stindex, i);
                    PrintArrangement(stindex+1);
                    Swap<T>(Data, stindex, i);
                }
            }

        }
        public static void Test()
        {
            Arrangement<int> arr = new Arrangement<int>();
            int[] data = new int[] {1,2,3};
            arr.SetInput(data);
            arr.PrintArrangement();
        }
    }
    //public class Arrangement2<T>
    //{
    //    class SortList<T>
    //    {
    //        List<T> set;
    //        public SortList(int capacity)
    //        {
    //            set = new List<T>(capacity);
    //        }
    //        public int AddUnique(T value)
    //        {
    //            if (!set.Contains(value))
    //            {
    //                set.Add(value);
    //            }
    //        }
    //    }


    //    T[] Data;
    //    SortedList<T>[] path;
    //    public void SetInput(T[] data)
    //    {
    //        this.Data = data;
    //    }
    //    public static void Swap<T>(T[] A, int index1, int index2)
    //    {
    //        T temp = A[index1];
    //        A[index1] = A[index2];
    //        A[index2] = temp;
    //    }
    //    public void PrintArrangement()
    //    {
    //        PrintArrangement(0);
    //    }
    //    private void PrintArrangement(int stindex)
    //    {
    //        if (stindex == Data.Length - 1)
    //        {
    //            for (int i = 0; i < Data.Length; i++)
    //            {
    //                Console.Write(Data[i]);
    //            }
    //            Console.Write("\n");
    //        }
    //        else
    //        {
    //            for (int i = stindex; i < Data.Length; i++)
    //            {
    //                Swap<T>(Data, stindex, i);
    //                PrintArrangement(stindex + 1);
    //                Swap<T>(Data, stindex, i);
    //            }
    //        }

    //    }
    //    public static void Test()
    //    {
    //        Arrangement2<int> arr = new Arrangement2<int>();
    //        int[] data = new int[] { 1, 2, 3 };
    //        arr.SetInput(data);
    //        arr.PrintArrangement();
    //    }
    //}
}
