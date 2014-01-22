#ifndef MYVECTOR_H
#define MYVECTOR_H
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
private:
	unsigned int my_size;
	unsigned int my_capacity;
	T * buffer;
};

template <class T>
T & Vector<T>::operator[]( unsigned int index )
{

}

template <class T>
void Vector<T>::resize( unsigned int size )
{

}

template <class T>
void Vector<T>::reserve( unsigned int capacity )
{

}

template <class T>
void Vector<T>::push_back( const T & value )
{

}

template <class T>
unsigned int Vector<T>::size() const
{

}

template <class T>
unsigned int Vector<T>::capacity() const
{

}

template <class T>
Vector<T>::~Vector()
{

}

template <class T>
Vector<T>::Vector( unsigned int size )
{

}

template <class T>
Vector<T>::Vector()
{

}

#endif