using System;
using System.Collections.Generic;
using System.Text;
using AlgsImp.Search;

namespace AlgsImp.Sort
{
    public class InsertSort<T>:ISorter<T> where T:IComparable<T>
    {
        public T[] A
        {
            get;
            set;
        }

        public void Sort()
        {
            for (int i = 1; i < A.Length; i++)
            {
                T value = A[i];
                int ins = GetInsertIndex3(i - 1, value);
                if (ins == i) { continue; }
                for (int j = i-1; j >= ins; j--)
                {
                    A[j + 1] = A[j];
                }
                A[ins] = value;
            }
        }

        private int GetInsertIndex(int to, T value)
        {
            for (int i = to; i >= 0; i--)
            {
                if (A[i].CompareTo(value) < 0)
                {
                    return i + 1;
                }
            }
            return 0;
        }

        private int GetInsertIndex2(int to, T value)
        {
            for (int i = 0; i <= to; i++)
            {
                if (A[i].CompareTo(value) > 0)
                {
                    return i ;
                }
            }
            return to + 1;
        }

        private int GetInsertIndex3(int to, T value)
        {
            bool found;
            int pos;
            BinarySearcher.BinarySearch(A, 0, to, value, out found, out pos);
            if (found)
                return pos + 1;
            else
                return pos;
        }
    }  
}
