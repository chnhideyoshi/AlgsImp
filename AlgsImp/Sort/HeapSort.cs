using System;
using System.Collections.Generic;
using System.Text;

namespace AlgsImp.Sort
{
    public class HeapSorter<T>:ISorter<T>
        where T : IComparable<T>
    {
        public T[] A
        { 
            get; set;
        }
        public void Sort()
        {
            int dynamicSize = A.Length;
            Build_Heap();//build heap
            for (int i = A.Length - 1; i >= 1; i--)
            {
                GeneralMethod.Swap(A , i, 0);
                dynamicSize--;
                Max_Heaplify(dynamicSize, 0);//
            }
        }

        private void Max_Heaplify(int size,int i)
        {
            int largestIndex = -1;
            int leftIndex = GetLeftChildIndex(i);
            int rightIndex = GetRightChildIndex(i);
            if (leftIndex <= size-1 && A[leftIndex].CompareTo(A[i]) > 0)
            {
                largestIndex = leftIndex;
            }
            else
            {
                largestIndex = i;
            }
            if (rightIndex <= size-1 && A[rightIndex].CompareTo(A[largestIndex]) > 0)
            {
                largestIndex = rightIndex;
            }
            if (largestIndex!=i)
            {
                GeneralMethod.Swap<T>(A,i, largestIndex);
                Max_Heaplify(size,largestIndex);
            }
        }
        private void Build_Heap()
        {
            for (int i = (A.Length - 1)/2; i >= 0; i--)
            {
                Max_Heaplify(A.Length,i);
            }
        }

        private int GetParentIndex(int i)
        {
            return i / 2;
        }
        private int GetLeftChildIndex(int i)
        {
            return i * 2;
        }
        private int GetRightChildIndex(int i)
        {
            return i * 2+1;
        } 
    }
}
