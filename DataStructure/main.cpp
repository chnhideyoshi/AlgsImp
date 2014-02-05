#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Vector.h"
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
#include "LinkedListR.h"

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
	Node<int>* node6=new Node<int>(6);
	list.InsertBeforeHead(node6);
	list.Display();
	list.Reverse();
	list.Display();
}

int main()
{
	TestLinkedList();
	system("pause");
	return 0;
}
