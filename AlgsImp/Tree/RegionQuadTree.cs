using System;
using System.Collections.Generic;
using System.Text;

namespace AlgsImp.Tree.RegionQuadTree
{
    public class Pixel
    {
        public Pixel(int x, int y)
        {
            this.X = x;
            this.Y = y;
        }
        public int X { get; set; }
        public int Y { get; set; }
    }
    public class Range
    {
        public Range(int xst, int xed,int yst,int yed)
        {
            this.XSt = xst;
            this.XEd = xed;
            this.YSt = yst;
            this.YEd = yed;
        }
        public int XSt { get; set; }
        public int XEd { get; set; }
        public int YSt { get; set; }
        public int YEd { get; set; }
        public int Squar { get { return (XEd - XSt + 1) * (YEd - YSt + 1); } }
        public override string ToString()
        {
            return string.Format("x[{0}~{1}]y[{2}~{3}]",XSt, XEd,YSt,YEd);
        }
    }
    public class Node
    {
        public Node()
        {

        }
        public Node(byte value, int xst, int xed,int yst,int yed)
        {
            RepresentedRange = new Range(xst, xed,yst,yed);
            Value = value;
        }
        //public Node Parent { get; set; }
        public Node NEChild { get; set; }
        public Node NWChild { get; set; }
        public Node SEChild { get; set; }
        public Node SWChild { get; set; }
        public Range RepresentedRange { get; set; }
        public byte Value = 127;
        public override string ToString()
        {
            string str;
            if (Value == RegionQuadTree.BlackValue)
                str = "B";
            else if (Value == RegionQuadTree.WhiteValue)
                str = "W";
            else
                str = "N";
            if (RepresentedRange != null)
            {
                return string.Format("{0}({1})", str, RepresentedRange);
            }
            else
            {
                throw new Exception();
            }
        }
    }
    public class RegionQuadTree
    {
        public static byte BlackValue = 0;
        public static byte WhiteValue = 255;
        Node blackNode;
        Node whiteNode;
        public Node Head { get; set; }
        public byte[] Data { get; set; }
        public int Width { get; set; }
        public int Height { get; set; }
        public RegionQuadTree()
        {
            blackNode = new Node();
            blackNode.Value = BlackValue;
            whiteNode = new Node();
            whiteNode.Value = WhiteValue;
        }
        public void SetData(byte[] Data, int width, int height)
        {
            if (Data == null)
                throw new Exception();
            if (Data.Length == 0)
                throw new Exception();
            this.Data = Data;
            Width = width;
            Height = height;
        }
        public void ConstructTree()
        {
            Head = RecursiveConstruct(0, Width - 1, 0, Height - 1);
        }
        private Node RecursiveConstruct(int xst, int xed, int yst, int yed)
        {
            if (xst > xed || yst > yed) { return null; }
            if (xst == xed && yst == yed)
            {
                if (Data[xst * Width + yst] == BlackValue)
                    return blackNode;
                else if (Data[xst * Width + yst] == WhiteValue)
                    return whiteNode;
                throw new Exception();
            }
            else
            {
                int xmid = (xst + xed) / 2;
                int ymid = (yst + yed) / 2;
                Node nec = RecursiveConstruct(xst, xmid, ymid+1, yed);
                Node nwc = RecursiveConstruct(xst, xmid, yst, ymid);
                Node swc = RecursiveConstruct(xmid + 1, xed, yst, ymid);
                Node sec = RecursiveConstruct(xmid + 1, xed, ymid + 1, yed);
                if (nec == nwc && nwc == swc && swc == sec)
                {
                    if (nec.Value == BlackValue)
                        return blackNode;
                    else if(nec.Value==WhiteValue)
                        return whiteNode;
                    throw new Exception();
                }
                else
                {
                    Node node = new Node();
                    node.RepresentedRange = new Range(xst,xed,yst,yed);
                    if(nec!=null&&nec.Value!=127)
                    {
                        node.NEChild = new Node(nec.Value, xst, xmid, ymid + 1, yed);
                    }
                    else
                    {
                        node.NEChild = nec;
                    }

                    if (nwc != null && nwc.Value != 127)
                    {
                        node.NWChild = new Node(nwc.Value, xst, xmid, yst, ymid);
                    }
                    else
                    {
                        node.NWChild = nwc;
                    }

                    if (swc != null && swc.Value != 127)
                    {
                        node.SWChild = new Node(swc.Value,xmid + 1, xed, yst, ymid);
                    }
                    else
                    {
                        node.SWChild = swc;
                    }

                    if (sec != null && sec.Value != 127)
                    {
                        node.SEChild = new Node(sec.Value,xmid + 1, xed, ymid + 1, yed);
                    }
                    else
                    {
                        node.SEChild = sec;
                    }
                    node.Value = 127;
                    return node;
                }
            }
        }

        private int InitCase(Node nec, Node nwc, Node swc, Node sec)
        {
            if (nec == null || nwc == null || swc == null || sec == null)
            {

            }
            return 0;
        }
    }
}
