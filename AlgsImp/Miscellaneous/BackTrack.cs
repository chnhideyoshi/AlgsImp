using System;
using System.Collections.Generic;
using System.Text;

namespace AlgsImp.Miscellaneous
{
    public class BackTrack<T>
    {
        protected T[] inputA;
        protected bool[] visited;
        public void SetInput(T[] input)
        {
            this.inputA = input;
            visited = new bool[inputA.Length];
        }
        public void Travel()
        {
            Travel(0,inputA.Length-1);
        }
        void Travel(int stindex,int edindex)
        {
            if (stindex > edindex)
            {
                if (Check())
                {
                    GetAResult();
                }
                return;
            }
            if (CanReduceBranch(stindex,edindex))
            {
                return;
            }

            visited[stindex] = true;
            Travel(stindex + 1, edindex);
            visited[stindex] = false;
            Travel(stindex+1, edindex);
        }

        protected virtual bool CanReduceBranch(int stindex, int edindex)
        {
            return false;
        }
        protected virtual bool Check()
        {
            return true;
        }
        protected virtual void GetAResult()
        {
            for (int i = 0; i < inputA.Length; i++)
            {
                if (visited[i])
                    Console.Write("1");
                else
                    Console.Write("0");
            }
            Console.Write("\n");
        }
        public static void Test1()
        {
            int[] a = new int[15] { 1, 2, 3, 4, 5 ,6,7,8,9,10,11,12,13,14,15};
            BackTrack<int> b = new BackTrack<int>();
            b.SetInput(a);
            b.Travel();
        }
    }
}
