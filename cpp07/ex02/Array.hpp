#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T				*arr;
		unsigned int	capacity;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array&	operator=(const Array& other);
		~Array() { if (this->arr) delete[] arr; }
		
		T&	operator[](unsigned int pos) const;
		unsigned int	size() const;

};

template <typename T>
Array<T>::Array() : arr(NULL), capacity(0) {}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->arr = new T[n]; 
	this->capacity = n;
}

template <typename T>
Array<T>::Array(const Array& other) : capacity(other.capacity)
{
	this->arr = new T[other.capacity];
	for (unsigned int i = 0; i < this->capacity; ++i)
		this->arr[i] = other.arr[i];
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other)
{
	if (*this == other)
		return (*this);
	if (this->arr)
		delete[] arr;
	this->arr = new T[other.capacity];
	this->capacity = other.capacity;
	for (unsigned int i = 0; i < this->capacity; ++i)
		this->arr[i] = other.arr[i];
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](unsigned int pos) const
{
	if (pos >= this->capacity)
		throw std::out_of_range("Out of range");
	return (this->arr[pos]);
}

template <typename T>
unsigned int	Array<T>::size() const { return (this->capacity); }

#endif
