using System;
using System.Collections.Generic;
using System.Text;

namespace AlgsImp.Miscellaneous
{
    public class SearchKth<T> where T :IComparable<T>
    {
        public T[] A{get;set;}
        public T Search(int K)
        {
            T result=default(T);
            Kth(A, 0, A.Length - 1,K,ref result);
            return result;
        }
        private void Kth(T[] A,int st, int ed,int K,ref T result)
        {
            if (st >= ed)
            {
                result = A[st];
                return;
            }
            int par = Partition(A, st, ed);
            if (par > K)
                Kth(A, st, par - 1, K, ref result);
            else
                Kth(A,par+1,ed,K-par,ref result);
        }
        public static int Partition(T[] A, int st, int ed)
        {
            int boundary = st;
            T value = A[st];
            for (int i = st + 1; i <= ed; i++)
            {
                if (A[i].CompareTo(value)<0)
                {
                    if(boundary+1!=i)
                        Swap(A, i, boundary + 1);
                    boundary++;
                }
            }
            Swap(A, st, boundary);
            return boundary;
        }
        public static void Swap(T[] A, int i, int p)
        {
            T temp = A[i];
            A[i] = A[p];
            A[p] = temp;
        }
    }
}
