#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <string.h>
#include <stdio.h>
template <class T>
class Vector
{
public:
	Vector();
	Vector(unsigned int size);
	~Vector();
	unsigned int capacity() const;
	unsigned int size() const;
	void push_back(const T & value);
	void reserve(unsigned int capacity);
	void resize(unsigned int size);
	T & operator[](unsigned int index);
	void Display()
	{
		printf("count: %d, capacity: %d ,",my_size,my_capacity);
		for(unsigned int i=0;i<my_size;i++)
		{
			printf("%d ",buffer[i]);
		}
	}
private:
	unsigned int my_size;
	unsigned int my_capacity;
	T * buffer;
};

template <class T>
T & Vector<T>::operator[]( unsigned int index )
{
	return buffer[index];
}

template <class T>
void Vector<T>::resize( unsigned int size )
{
	reserve(size);
	size = size;
}

template <class T>
void Vector<T>::reserve( unsigned int capacity )
{
	if(buffer == 0)
	{
		my_size = 0;
		my_capacity = 0;
	}
	T * b = new T [capacity];
	memcpy(b,this->buffer,my_size*sizeof(T));
	my_capacity = capacity;
	delete[] this->buffer;
	this->buffer = b;
}

template <class T>
void Vector<T>::push_back( const T & v )
{
	if (my_size >= my_capacity)
		reserve(my_capacity +5);
	buffer [my_size++] = v;
}

template <class T>
unsigned int Vector<T>::size() const
{
	return my_size;
}

template <class T>
unsigned int Vector<T>::capacity() const
{
	return my_capacity;
}

template <class T>
Vector<T>::~Vector()
{
	 delete []buffer;
}

template <class T>
Vector<T>::Vector( unsigned int size )
{
	my_capacity = size;
	my_size = size;
	buffer = new T[size];
}

template <class T>
Vector<T>::Vector()
{
	my_capacity = 0;
	my_size = 0;
	buffer = 0;
}

#endif
