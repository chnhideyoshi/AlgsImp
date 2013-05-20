using System;
using System.Collections.Generic;
using System.Text;

namespace AlgsImp.Sort
{
    public class QuickSorter<T>:ISorter<T> where T:IComparable<T>
    {

        public T[] A
        {
            get;
            set;
        }

        public void Sort()
        {
            QuickSort(A, 0, A.Length - 1);
        }
        public void QuickSort(T[] A,int st,int ed)
        {
            if (st < ed)
            {
                int pa = Partition(A, st, ed, (st+ed)/2);
                QuickSort(A, st, pa - 1);
                QuickSort(A, pa + 1, ed);
            }
        }
        private int Partition(T[] A,int st,int ed,int partionPos)//SELECT VALUE ON PAPOS AND MAKE THE ARRAY(ST TO ED) INTO TWO PARTS: BEFORE RET SMALLER THAN VALUE AFTER BIGGER
        {
            if(partionPos!=st)
                GeneralMethod.Swap(A, partionPos, st);

            T value = A[st];
            int boundary=st;//BOUNDARY REFER TO THE LAST SMALLER INDEX

            for (int i = st+1; i <= ed; i++)
            {
                if (A[i].CompareTo(value) < 0)
                {
                    if(boundary+1!=i)
                        GeneralMethod.Swap(A, i, boundary+1);
                    boundary++;
                }
            }
            if(st!=boundary)
                GeneralMethod.Swap(A, boundary , st);
            return boundary;
        }
    }
}
