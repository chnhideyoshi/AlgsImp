                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             using System;
using System.Collections.Generic;
using System.Text;

namespace AlgsImp.Sort
{
    public class MergeSorter<T>:ISorter<T> where T:IComparable<T> 
    {

        public T[] A
        {
            get;
            set;
        }
        T[] C = null;
        public void Sort()
        {
            C= new T[A.Length];
            ExcuteMergeSort(A, 0, A.Length - 1);
        }
        private void ExcuteMergeSort(T[] A, int st, int ed)
        {
            if (ed == st) { return; }
            else
            {
                int mid = (st + ed) / 2;
                ExcuteMergeSort(A, st, mid);
                ExcuteMergeSort(A, mid+1, ed);
                MergeArray(A, st, mid, A, mid + 1, ed, C, st);
                CopyArray(C, st, ed, A, st);
            }
        }
        public void CopyArray(T[] from, int fromSt, int fromEd, T[] to,int toSt)
        {
            for (int i = fromSt; i <= fromEd; i++)
            {
                to[toSt] = from[i];
                toSt++;
            }
        }
        public void MergeArray(T[] A, int ast, int aed, T[] B, int bst, int bed, T[] C, int cst)
        {
            int pointerA = ast;
            int pointerB = bst;
            int lenA=aed-ast+1;
            int lenB=bed-bst+1;
            for (int i = cst; i <= cst + lenA + lenB - 1; i++)
            {
                if (pointerA > aed||pointerB>bed)
                {
                    if (pointerA > aed)
                    {
                        for (int j = i; j <= cst + lenA + lenB - 1; j++)
                        {
                            C[j] = B[pointerB];
                            pointerB++;
                        }
                        return;
                    }
                    if (pointerB > aed) 
                    {
                        for (int j = i; j <= cst + lenA + lenB - 1; j++)
                        {
                            C[j] = A[pointerA];
                            pointerA++;
                        }
                        return;
                    }
                }
                else 
                {
                    if (A[pointerA].CompareTo(B[pointerB]) < 0)
                    {
                        C[i] = A[pointerA];
                        pointerA++;
                    }
                    else
                    {
                        C[i] = B[pointerB];
                        pointerB++;
                    }
                }
            }
          
        }
    }
}
