using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;

namespace AlgsImp.Sort
{
    public class BubbleSort<T> : ISorter<T> where T : IComparable<T>
    {

        public T[] A
        {
            get;
            set;
        }

        public void Sort()
        {
            ForwardSort();
            //bubble_sort(A, A.Length);
        }
        private void ForwardSort()
        {
            for (int i = A.Length - 1; i >= 0; i--)
            {
                bool hasSwap = BubbleForward(0, i);
                if (!hasSwap)
                    break;
            }
            //for (int i = 0; i <=A.Length-1; i++)  
            //{
            //    bool hasSwap = BubbleForward(0,A.Length-i-1);
            //    if (!hasSwap)
            //        break;
            //}
        }
        private void ReverseSort()
        {
            for (int i = 0; i <= A.Length - 2; i++)
            {
                bool hasSwap = BubbleReverse(i, A.Length - 1);
                if (!hasSwap)
                    break;
            }
        }

        private bool BubbleForward(int st, int ed)
        {
            bool hasSwap = false;
            for (int i = st; i <= ed - 1; i++)
            {
                if (A[i].CompareTo(A[i + 1]) > 0)
                {
                    GeneralMethod.Swap(A, i, i + 1);
                    hasSwap = true;
                }
            }
            return hasSwap;
        }
        private bool BubbleReverse(int st, int ed)
        {
            bool hasSwap = false;
            for (int i = ed - 1; i >= st; i--)
            {
                if (A[i].CompareTo(A[i + 1]) > 0)
                {
                    GeneralMethod.Swap(A, i, i + 1);
                    hasSwap = true;
                }
            }
            return hasSwap;
        }

        private void bubble_sort(T[] array, int n)
        {
            int i, j, flag;
            T temp;
            for (i = 0; i < n - 1; i++)
            {
                for (j = 0; j < n - i - 1; j++)
                {
                    if (array[j].CompareTo(array[j + 1])>0)
                    {
                        temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
            }
            return;
        }
    }
}
