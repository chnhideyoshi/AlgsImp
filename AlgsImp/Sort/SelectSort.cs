using System;
using System.Collections.Generic;
using System.Text;

namespace AlgsImp.Sort
{
    public class SelectSorter<T>:ISorter<T> where T :IComparable<T>
    {

        public T[] A
        {
            get;
            set;
        }

        public void Sort()
        {
            for (int i = 0; i < A.Length - 1; i++)
            {
                GeneralMethod.Swap<T>(A, i, FindMinIndex(i, A.Length - 1));
            }
        }

        private int FindMinIndex(int st, int ed)
        {
            int record=st;
            for (int i = st+1; i <= ed; i++)
            {
                if (A[record].CompareTo(A[i]) > 0)
                {
                    record = i;
                }
            }
            return record;
        }
    }
}
