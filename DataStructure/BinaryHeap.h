#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include <vector>
#include <algorithm>
#include<iterator>
#include "Base.h"
template<class T>
class BinaryHeap
{
private:
	std::vector<T> heapArray;
public:
	BinaryHeap()
	{

	}
	~BinaryHeap()
	{

	}
	int Count()
	{
		return heapArray.size();
	}
	void Add(T value)
	{
		heapArray.push_back(value);
		ShiftUp(Count()-1);
	}
	T ExtractTop()
	{
		if(Count()==0)
			return -1;
		T p=heapArray[0];
		Swap(0,Count()-1);
		heapArray.pop_back();
		ShiftDown(0);
		return p;
	}
	T Top()
	{
		return heapArray[0];
	}
	void Heapify(T* data,int size)
	{
		std::copy(data, data + size, std::back_inserter(heapArray));
		for(int i=size-1;i>=0;i--)
			ShiftDown(i);
	}
	void HeapSort(T* data,int size)
	{
		Heapify(data,size);
		for(int i=0;i<size;i++)
		{
			data[i]=ExtractTop();
		}
	}
	bool IsEmpty()
	{
		return heapArray.size()==0;
	}
protected:
	bool LessThan(T a,T b)
	{
		return a<b;
	}
private:
	int GetParent(int index)
	{
		return (index-1)/2;
	}
	int GetLeftChild(int index)
	{
		return 2*index+1;
	}
	int GetRightChild(int index)
	{
		return 2*index+2;
	}
	bool IsLessThan(int index0,int index1)
	{
		return LessThan(heapArray[index0],heapArray[index1]);
	}
	void ShiftUp(int i)
	{
		if (i == 0)
			return;
		else
		{
			int parent = GetParent(i);
			if (IsLessThan(i,parent))
			{
				Swap(i, parent);
				ShiftUp(parent);
			}
		}
	}
	void ShiftDown(int i)
	{
		if (i >= Count()) return;
		int min = i;
		int lc = GetLeftChild(i);
		int rc = GetRightChild(i);
		if (lc < Count() && IsLessThan(lc,min))
			min = lc;
		if (rc < Count() && IsLessThan(rc,min))
			min = rc;
		if (min != i)
		{
			Swap(i, min);
			ShiftDown(min);
		}
	}
	void Swap(int i, int j)
	{
		T temp = heapArray[i];
		heapArray[i] = heapArray[j];
		heapArray[j] = temp;
	}

};



#endif