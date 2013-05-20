using System;
using System.Collections.Generic;
using System.Text;

namespace AlgsImp.Miscellaneous
{
    public class SortedRemoveDuplicates<T> where T:IComparable<T>
    {
        T[] data;
        public void SetInput(T[] data)
        {
            this.data = data;
        }
        public int Execute()
        {
            int lastIndex = 0;
            for (int i = 0; i < data.Length; i++)
            {
                if (data[i].CompareTo(data[lastIndex]) == 0)
                {
                    continue;
                }
                else
                {
                    data[lastIndex + 1] = data[i];
                    lastIndex++;
                }
            }
            return lastIndex+1;
        }
        public static void Test()
        {
            int[] array = new int[] {1,2,2,3,3,3,4,4,5,5,5,5,5,6,6,7,8,9,9,10 };
            SortedRemoveDuplicates<int> filter = new SortedRemoveDuplicates<int>();
            filter.SetInput(array);
            int newlen=filter.Execute();
            for (int i = 0; i < newlen; i++)
            {
                Console.Write(array[i] + " ");
            }
            Console.Write("\n");
        }
    }
    public class ArrayRemove<T> where T:IComparable<T>
    {
        T[] data;
        public void SetInput(T[] data)
        {
            this.data = data;
        }
        public int Execute(T target)
        {
            int lastIndex = 0;
            for (int i = 0; i < data.Length; i++)
            {
                if (target.CompareTo(data[i])!=0)
                {
                    if(lastIndex!=i)
                        data[lastIndex] = data[i];
                    lastIndex++;
               }
            }
            return lastIndex;
        }
        public static void Test()
        {
            int[] array = new int[] { 1, 2,3, 4 ,5, 6, 7,8, 9, 10, 11, 12, 9, 14, 15, 9, 17, 9, 19, 20 };
            ArrayRemove<int> filter = new ArrayRemove<int>();
            filter.SetInput(array);
            int newlen = filter.Execute(9);
            for (int i = 0; i < newlen; i++)
            {
                Console.Write(array[i] + " ");
            }
            Console.Write("\n");
        }
    }
}
