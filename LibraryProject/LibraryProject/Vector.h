#pragma once
#include <iostream>

template <class T>
class Vector {
private:
	T* data;
	int size;

public:
	Vector() {
		this->size = 0;
		this->data = nullptr;
	};
	Vector(int creationSize) {
		this->size = creationSize;
		this->data = new T[this->size];
	};

	void push(const T& newElement) {
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
	};

	void push_back(const T& newElement) {
		T* result = new T[this->size + 1];
		for (size_t i = 0; i < this->size; i++)
		{
			result[i] = data[i];
		}
		result[this->size] = newElement;

		delete[] data;
		this->data = result;
		this->size += 1;
	};
	size_t length() const {
		return this->size;
	};

	T& operator[] (size_t index) {
			return this->data[index];
	};

	Vector<T>& operator= (const Vector<T>& otherVector) {
		if (this != &otherVector)
		{
			delete[]data;

			this->size = otherVector.size;
			this->data = new T[otherVector.size];
			for (size_t i = 0; i < size; ++i)
			{
				this->data[i] = otherVector.data[i];
			}
		}
		return *this;
	}

	~Vector() {
		delete[] this->data;
	};
};