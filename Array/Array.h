#pragma once
#include <stdexcept>

template <typename T>
class Array
{
public:
	Array();
	virtual ~Array();
	Array<T>& operator = (const Array<T> rhs) = delete;
	Array(const Array<T>&src) = delete;
	T& operator[](size_t x);
	const T& operator[] (size_t x) const;
	T getElementAt(size_t x) const;
	void setElementAt(size_t x, const T& val);

private:
	static const size_t kAllocSize = 4;
	void resize(size_t newSize);
	void initializedElements();
	T* mElems;
	size_t mSize;
};


template <typename T>
Array<T>::Array()
{
	mSize = kAllocSize;
	mElems = new T[mSize];
	initializedElements();

}

template <typename T>
Array<T>::~Array()
{
	delete[] mElems;
	mElems = nullptr;
}

template <typename T>
T& Array<T>::operator[](size_t x)
{
	if(x >= mSize)
	{
		resize(x + kAllocSize);
	}
	return mElems[x];
}

template <typename T>
const T& Array<T>::operator[](size_t x) const
{
	if (x >= mSize)
	{
		throw std::out_of_range("");
	}
	return mElems[x];

}

template <typename T>
T Array<T>::getElementAt(size_t x) const
{
	if (x >= mSize)
	{
		throw std::out_of_range("");
	}
	return mElems[x];
}

template <typename T>
void Array<T>::setElementAt(size_t x, const T& val)
{
	if (x >= mSize)
	{
		resize(x + kAllocSize);
	}
	mElems[x] = val;
}

template <typename T>
void Array<T>::resize(size_t newSize)
{
	T* oldElems = mElems;
	size_t oldSize = mSize;
	mSize = newSize;
	mElems = new T[newSize];
	initializedElements();
	for (size_t i = 0; i < oldSize; ++i)
		mElems[i] = oldElems[i];
	delete[] oldElems;
}

template <typename T>
void Array<T>::initializedElements()
{
	for (size_t i = 0; i < mSize; i++)
		mElems[i] = T();
}
