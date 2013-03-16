using System;
using System.Collections.Generic;
using System.Text;

namespace AlgsTest.RegionBinaryTree
{
    public class Range1d
    {
        public Range1d(int st, int ed)
        {
            this.St = st;
            this.Ed = ed;
        }
        public int St { get; set; }
        public int Ed { get; set; }
        public int Mid { get { return (St + Ed) / 2; } }
        public int Length { get { return Ed - St + 1; } }
        public override string ToString()
        {
            return string.Format("[{0},{1}]",St,Ed);
        }
    }
    public class Node
    {
        public Node()
        {

        }
        public Node(byte value,int st,int ed)
        {
            RepresentedRange = new Range1d(st, ed);
            Value = value;
        }
        //public Node Parent { get; set; }
        public Node LChild { get; set; }
        public Node RChild { get; set; }
        public Range1d RepresentedRange { get; set; }
        public byte Value = 127;
        public override string ToString()
        {
            string str;
            if(Value==RegionBinaryTree.blackValue)
                str="B";
             else if(Value==RegionBinaryTree.whiteValue)
                str="W";
            else
                str="N";
            if (RepresentedRange != null)
            {
                return string.Format("{0}[{1},{2}]",str,RepresentedRange.St,RepresentedRange.Ed);
            }
            else
            {
                throw new Exception();
            }
        }
    }
    public delegate void TravelAction(Node node,object parameter);
    public class RegionBinaryTree
    {
        byte[] Data = null;
        public Node blackNode;
        public Node whiteNode;
        public static byte blackValue = 0;
        public static byte whiteValue = 255;
        public Node Head { get; set; }
        public RegionBinaryTree()
        {
            blackNode = new Node();
            blackNode.Value=blackValue;
            whiteNode = new Node();
            whiteNode.Value = whiteValue;
        }
        public void SetData(byte[] Data)
        {
            if (Data == null)
                throw new Exception();
            if (Data.Length == 0)
                throw new Exception();
            this.Data = Data;
        }
        public void ConstructTree()
        {
            Head = RecursiveConstruct( 0, Data.Length - 1);
        }
        private Node RecursiveConstruct(int st, int ed)
        {
            if (st == ed)
            {
                if (Data[st] == blackValue)
                {
                    return blackNode;
                }
                else if (Data[st] == whiteValue)
                {
                    return whiteNode;
                }
                else
                {
                    throw new Exception();
                }
            }
            else
            {
                int mid = (st + ed )/ 2;
                Node L= RecursiveConstruct(st, mid);
                Node R=RecursiveConstruct(mid + 1, ed);
                if (L == whiteNode && R == whiteNode)
                {
                    return whiteNode;
                }
                else if (L == blackNode && R == blackNode)
                {
                    return blackNode;
                }
                else
                {
                    if (L == whiteNode || L == blackNode)
                    {
                        byte value = L.Value;
                        L = new Node(value, st, mid);
                    }
                    if (R == whiteNode || R== blackNode)
                    {
                        byte value = R.Value;
                        R = new Node(value, mid + 1, ed);
                    }
                    Node node=new Node();
                    node.RepresentedRange=new Range1d(st,ed);
                    node.LChild=L;
                    node.RChild=R;
                    node.Value = 127;
                    return node;
                }
            }
        }
        public void Travel(TravelAction action,object parameter)
        {
            if (action == null)
                throw new Exception();
            RecursiveTravel(Head,action,parameter);
        }
        private void RecursiveTravel(Node node, TravelAction action, object parameter)
        {
            if (node != null)
            {
                action(node,parameter);
                if (node.LChild != null)
                    RecursiveTravel(node.LChild, action,parameter);
                if (node.RChild != null)
                    RecursiveTravel(node.RChild, action,parameter);
           }
        }
    }
    public class RegionBinaryTreeTest
    {
        public static void CountWhiteNode(Node node,object time)
        {
            if (node.Value == 255)
            {
                int[] a = (int[])time;
                a[0] += node.RepresentedRange.Length;
            }
        }
        public static void FindBoundary(Node node,object p)
        {
            if (node.LChild != null && node.RChild != null)
                {
                    if (node.LChild.Value == RegionBinaryTree.blackValue && node.RChild.Value == RegionBinaryTree.whiteValue)
                    {
                        int st = node.LChild.RepresentedRange.Ed;
                        int ed = node.RChild.RepresentedRange.St;
                        Console.WriteLine(st+","+ed);
                    }
                    if (node.LChild.Value == RegionBinaryTree.whiteValue && node.RChild.Value == RegionBinaryTree.blackValue)
                    {
                        int st = node.LChild.RepresentedRange.Ed;
                        int ed = node.RChild.RepresentedRange.St;
                        Console.WriteLine(st + "," + ed);
                    }
                }
        }
    }
}
