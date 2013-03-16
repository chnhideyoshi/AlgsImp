using System;
using System.Collections.Generic;
using System.Text;

namespace AlgsImp.Search
{
    public static class BinarySearcher
    {
        public static void BinarySearch<T>(T[] A, int st, int ed, T value,out bool found, out int pos) where T : IComparable<T>
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               {
            int left = st;
            int right = ed;
            while (left <=right)
            {
                int mid = (left + right) / 2;
                //Console.Write(mid + " ");
                if (A[mid].CompareTo(value) == 0)
                {
                    found = true;
                    pos=mid;
                    return;
                }
                else
                {
                    if (A[mid].CompareTo(value) > 0)
                    {
                        right = mid-1;
                    }
                    else
                    {
                        left = mid+1;
                    }
                }
            }

            found = false;
            pos = left;
            return ;
        }
    }
}
