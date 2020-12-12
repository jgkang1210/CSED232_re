#ifndef POKEVECTOR
#define POKEVECTOR

#include "Pokemon.h"

template <typename T>
class Pokevector
{
private:
	int length;
	int maxLength;
	T* arr;

public:
	// constructor
	Pokevector();

	// destructor
	~Pokevector();

	int size() const;
	T at(const int& index) const;
	void push_back(T obj);
	void erase(const int& index);
	void plus(const int& index);
};

// initial length = 0, capacity = 10
template<typename T>
inline Pokevector<T>::Pokevector() : length(0), maxLength(10)
{
	arr = new T[maxLength];
}

template<>
inline Pokevector<Pokemon*>::~Pokevector()
{
	// delete each member
	for (int i = 0; i < this->length; i++) {
		delete arr[i];
	}
}

template<typename T>
inline Pokevector<T>::~Pokevector()
{
}

template<typename T>
inline int Pokevector<T>::size() const
{
	return length;
}

template<typename T>
inline T Pokevector<T>::at(const int& index) const
{
	return arr[index];
}

template<typename T>
inline void Pokevector<T>::push_back(T obj)
{
	if (length == maxLength) {
		// assign new memory
		maxLength += 10;
		// make temp
		T* temp = new T[maxLength];
		for (int i = 0; i < length; i++) {
			temp[i] = arr[i];
		}
		// Delete the original arr, not delete the data.
		arr = nullptr;
		// re assign
		arr = temp;
	}

	arr[length] = obj;
	length++;
}

template<>
inline void Pokevector<Pokemon*>::erase(const int& index)
{
	// 1. check the type
	// if pokemon --> use delete
	delete arr[index];
	arr[index] = nullptr;
	length--;

	// 2. re arrange the array
	for (int i = index; i <= length; i++) {
		arr[i] = arr[i + 1];
	}
	arr[length] = nullptr;
}

template<typename T>
inline void Pokevector<T>::erase(const int& index)
{
	// 1. length -
	length--;
	
	// 2. re arrange the array
	for (int i = index; i <= length; i++) {
		arr[i] = arr[i + 1];
	}
}

template<>
inline void Pokevector<int>::plus(const int& index)
{
	arr[index]++;
}

template<typename T>
inline void Pokevector<T>::plus(const int& index)
{
}
#endif