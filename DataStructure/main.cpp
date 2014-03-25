#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define DataType int
#include "Vector.h"
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
#include "LinkedListR.h"
#include "Tree.h"
#include "Graph.h"
#include "ShortestPath.h"
#include "MinimumTree.h"
#include "BinaryHeap.h"
#include "HashTable.h"

using namespace std;

void TestVector()
{
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.Display();
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.Display();

}
void TestStack()
{
	Stack<int> v;
	v.Push(1);
	v.Push(2);
	v.Push(3);
	v.Push(4);
	v.Push(5);
	v.Display();
	v.Push(1);
	v.Push(2);
	v.Push(3);
	v.Push(4);
	v.Push(5);
	v.Display();
}
void TestQueue()
{
	Queue<int> v;
	v.Enqueue(1);
	v.Enqueue(2);
	v.Enqueue(3);
	v.Enqueue(4);
	v.Enqueue(5);
	v.Enqueue(6);
	v.Enqueue(7);
	v.Enqueue(8);
	v.Dequeue();
	v.Dequeue();
	v.Dequeue();
	v.Dequeue();
	v.Dequeue();
	v.Dequeue();
	v.Enqueue(9);
	v.Enqueue(10);
	v.Enqueue(11);
	v.Enqueue(12);
	v.Enqueue(13);
	v.Enqueue(14);
	v.Enqueue(15);
	v.Enqueue(16);
	v.Dequeue();
	v.Dequeue();
	v.Dequeue();
	v.Display();
}
void TestLinkedList()
{
	LinkedList<int> list;
	Node<int>* node1=new Node<int>(1);
	Node<int>* node2=new Node<int>(2);
	Node<int>* node3=new Node<int>(3);
	Node<int>* node4=new Node<int>(4);
	Node<int>* node5=new Node<int>(5);
	list.InsertAfterTail(node1);
	list.InsertAfterTail(node2);
	list.InsertAfterTail(node3);
	list.InsertAfterTail(node4);
	list.InsertAfterTail(node5);
	Node<int>* node6=new Node<int>(0);
	list.InsertBeforeHead(node6);
	list.Display();
	list.Reverse();
	list.Display();
	Node<int>* node7=new Node<int>(8);
	list.InsertAfter(node7,4);
	list.Display();
	list.DeleteAt(2);
	list.Display();
	list.DeleteTail();
	list.Display();
	list.DeleteHead();
	list.Display();


}
void TestLinkedListR()
{
	LinkedListR<int> list;
	NodeR<int>* node1=new NodeR<int>(1);
	NodeR<int>* node2=new NodeR<int>(2);
	NodeR<int>* node3=new NodeR<int>(3);
	NodeR<int>* node4=new NodeR<int>(4);
	NodeR<int>* node5=new NodeR<int>(5);
	list.InsertAfterTail(node1);
	list.InsertAfterTail(node2);
	list.InsertAfterTail(node3);
	list.InsertAfterTail(node4);
	list.InsertAfterTail(node5);
	NodeR<int>* node6=new NodeR<int>(0);
	list.InsertBeforeHead(node6);
	list.Display();
	list.Reverse();
	list.Display();
	NodeR<int>* node7=new NodeR<int>(8);
	list.InsertAfter(node7,4);
	list.Display();
	list.DeleteAt(2);
	list.Display();
	list.DeleteTail();
	list.Display();
	list.DeleteHead();
	list.Display();


}
void TestLinkedListC()
{
	LinkedListR<int> list;
	NodeR<int>* node1=new NodeR<int>(1);
	NodeR<int>* node2=new NodeR<int>(2);
	NodeR<int>* node3=new NodeR<int>(3);
	NodeR<int>* node4=new NodeR<int>(4);
	NodeR<int>* node5=new NodeR<int>(5);
	list.InsertAfterTail(node1);
	list.InsertAfterTail(node2);
	list.InsertAfterTail(node3);
	list.InsertAfterTail(node4);
	list.InsertAfterTail(node5);
	NodeR<int>* node6=new NodeR<int>(0);
	list.InsertBeforeHead(node6);
	list.Display();
	list.Reverse();
	list.Display();
	NodeR<int>* node7=new NodeR<int>(8);
	list.InsertAfter(node7,4);
	list.Display();
	list.DeleteAt(2);
	list.Display();
	list.DeleteTail();
	list.Display();
	list.DeleteHead();
	list.Display();


}
void TestTree()
{
	/*BinarySearchTree tree;
	tree.Insert(5);
	tree.Insert(3);
	tree.Insert(4);
	tree.Insert(1);
	tree.Insert(2);
	tree.Insert(9);
	tree.Insert(6);
	tree.Insert(8);
	tree.Insert(7);
	tree.Display();*/
	BinarySearchTree bstree;
	bstree.Insert(32);
	bstree.Insert(21);
	bstree.Insert(46);
	bstree.Insert(54);
	bstree.Insert(16);
	bstree.Insert(38);
	bstree.Insert(70);
	cout<<"inorder tree walk is: ";
	bstree.Travel(InOrder,BinarySearchTree::Print);
	cout<<"\nmax value is: "<<bstree.GetMax()<<endl;
	cout<<"min value is: "<<bstree.GetMin()<<endl;
	bool ptnode = bstree.Exist(38);
	if(ptnode)
		cout<<"the element 38 is exist in the binary tree.\n";
	else
		cout<<"the element 38 is not exist in the binary tree.\n";
	cout<<"the successor of 38 is: "<<bstree.GetSuccessor(38)<<endl;
	cout<<"the predecessor of 38 is:"<<bstree.GetPredecessor(38)<<endl;
	if(bstree.Delete(46))
		cout<<"delete 46 successfully"<<endl;
	else
		cout<<"delete 46 failed"<<endl;
	cout<<"inorder tree walk is: ";
	bstree.Travel(InOrder,BinarySearchTree::Print);
}
void TestShortestPath()
{
	UndirectedWeightedGraph graph(6);
	graph.AddEdge(0,1,4);
	graph.AddEdge(0,2,2);
	graph.AddEdge(1,2,1);
	graph.AddEdge(1,4,3);
	graph.AddEdge(2,4,2);
	graph.AddEdge(2,3,4);
	graph.AddEdge(3,4,3);
	graph.AddEdge(3,5,2);
	graph.AddEdge(4,5,2);
	DijkstraProcessor dp(&graph,0);
	dp.ExecuteDijkstra();
	std::vector<int> path1;
	std::vector<int> path2;
	std::vector<int> path3;
	std::vector<int> path4;
	std::vector<int> path5;
	dp.GetShortestPathTo(1,path1);
	dp.GetShortestPathTo(2,path2);
	dp.GetShortestPathTo(3,path3);
	dp.GetShortestPathTo(4,path4);
	dp.GetShortestPathTo(5,path5);
	DijkstraProcessor::PrintPath(path1);
	DijkstraProcessor::PrintPath(path2);
	DijkstraProcessor::PrintPath(path3);
	DijkstraProcessor::PrintPath(path4);
	DijkstraProcessor::PrintPath(path5);
	printf("%d\n",dp.GetShortestDistenceTo(1));
	printf("%d\n",dp.GetShortestDistenceTo(2));
	printf("%d\n",dp.GetShortestDistenceTo(3));
	printf("%d\n",dp.GetShortestDistenceTo(4));
	printf("%d\n",dp.GetShortestDistenceTo(5));
}
void TestHeap()
{
	int a[10]={2,5,1,4,6,3,9,8,11,10};
	int len=sizeof(a)/sizeof(int);
	BinaryHeap<int> heap;
	heap.HeapSort(a,len);
	for(int i=0;i<len;i++)
	{
		printf("%d,",a[i]);
	}
}
void TestHash()
{
	HashTable_LinkedList<int,int> hash;
	int rand[17]={1,2,3,1,2,3,1,3,1,2,3,1,2,3,1,1,1};
	for(int i=0;i<17;i++)
	{
		if(!hash.Exist(rand[i]))
		{
			hash.SetValue(rand[i],1);
		}
		else
		{
			int count=hash.GetValue(rand[i]);
			count++;
			hash.SetValue(rand[i],count);
		}
	}
	printf("%d: \n",hash.GetValue(1));
	printf("%d: \n",hash.GetValue(2));
	printf("%d: \n",hash.GetValue(3));
}

int main()
{
	TestHash();
	system("pause");
	return 0;
}
