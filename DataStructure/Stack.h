#ifndef  MYSTACK_H
#define MYSTACK_H
#include "string.h"

template<class T>
class Stack
{
private:
	T* buffer;
	int size;
	int capacity;
	void reserve( unsigned int capacity )
	{
		T * b = new T [capacity];
		memcpy(b,this->buffer,size*sizeof(T));
		this->capacity = capacity;
		delete[] this->buffer;
		this->buffer = b;
	}
public: 
	Stack(int capacity=0)
	{
		if(capacity == 0)
			buffer = 0;
		else
			buffer=new int[capacity];
		this->size=0;
		this->capacity=capacity;
	}
	~Stack()
	{
		if(buffer!=0)
			delete[] buffer;
	}
	void Push(const T& value)
	{
		if(size==capacity)
		{
			reserve(capacity+5);
		}
		buffer[size]=value;
		size++;
	}
	T& Top() const
	{
		if(size>0)
		{
			return buffer[size-1];
		}
		else
			throw std::exception();
	}
	void Pop()
	{
		if(size>0)
		{
			size--;
		}
		else
			throw std::exception();
	}
	bool IsEmpty() const
	{
		return size==0;
	}
    int Size() const
	{
		return size;
	}
	void Display()
	{
		printf("count: %d, capacity: %d ,",size,capacity);
		for(int i=0;i<size;i++)
		{
			printf("%d ",buffer[i]);
		}
	}
};


#endif