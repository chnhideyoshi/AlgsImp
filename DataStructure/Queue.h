#ifndef MYQUEUE_H
#define MYQUEUE_H
#include "string.h"

template<class T>
class Queue
{
private:
	T* buffer;
	int capacity;
	int head;
	int tail;
	void reserve( unsigned int capacity )
	{
		T * b = new T [capacity];
		int tempsize=Size();
		if(head<=tail)
		{
			memcpy(b,this->buffer+head,tail-head+1);
			head=0;
			tail=tempsize-1;
		}
		else
		{
			memcpy(b,this->buffer+head,this->capacity-head);
			memcpy(b+this->capacity-head,this->buffer,tail+1);
			head=0;
			tail=tempsize-1;
		}
		this->capacity = capacity;
		delete[] this->buffer;
		this->buffer = b;
	}
public:
	Queue(int capacity=0)
	{
		if(capacity==0)
		{
			this->buffer=0;
			this->capacity=0;
			this->head=0;
			this->tail=-1;
		}
		else
		{
			this->capacity=capacity;
			this->buffer=new T[capacity];
			this->head=0;
			this->tail=-1;
		}
	}
	~Queue()
	{

	}
	int Size() const
	{
		if(capacity<=0)
			return 0;
		if(tail>=head)
			return tail-head+1;
		else
			return capacity+tail-head+1;
	}
	bool IsEmpty() const
	{
		return Size()==0;
	}
	void Enqueue(const T& value)
	{
		if(Size()==capacity)
		{
			reserve(capacity+10);
		}
		if(tail+1<capacity)
		{
			tail++;
			buffer[tail]=value;
		}
		else
		{
			tail=0;
			buffer[0]=value;
		}
	}
	T& Top() const
	{
		if(Size()!=0)
			return buffer[head];
		else
			throw std::exception();
	}
	void Dequeue()
	{
		if(Size()>0)
		{
			head++;
			if(head==capacity)
				head=0;
		}
	}
	void Display()
	{
		printf("capacity: %d ,",capacity);
		if(head<=tail)
		{
			for(int i=head;i<=tail;i++)
			{
				printf("%d ",buffer[i]);
			}
		}
		else
		{
			for(int i=head;i<=tail+capacity;i++)
			{
				printf("%d ",buffer[i%capacity]);
			}
		}
		
	}
};

#endif