#include <iostream>
#include "Vector.h"

template <class T>
Vector<T>::Vector()
{
	this->size = 0;
	this->data = nullptr;
}
template <class T>
Vector<T>::Vector(int creationSize)
{
	this->size = creationSize;
	this->data = new T[this->size];
}

template <class T>
void Vector<T>::push(const T& newElement)
{
	T* result = new T[this->size + 1];
	for (int i = 0; i < size; i++)
	{
		//Dobavqme element otzad napred, posledniq na noviq +1 e raven na posledniq ot stariq koeto e normalno i
		result[i + 1] = this->data[i];
	}

	result[0] = newElement;
	this->size += 1;
	delete[]data;
	data = result;
}

template <class T>
void Vector<T>::push_back(const T& newElement)
{
	T* result = new T[this->size + 1];
	for (size_t i = 0; i < this->size; i++)
	{
		result[i] = data[i];
	}
	result[this->size] = newElement;

	delete[] data;
	this->data = result;
}

template <class T>
size_t Vector<T>::length() const
{
	return this->size;
}

template <class T>
T& Vector<T>::operator[](size_t index)
{
	if (index > 0 && index < this->size)
	{
		return this->data[index];
	}
	return nullptr;
}

template<class T>
Vector<T>::~Vector()
{
	delete[] this->data;
}
