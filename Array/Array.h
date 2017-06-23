#pragma once

template <typename T>
class Array
{
public:
	Array();
	virtual ~Array();
		

	Array<T>& operator = (const Array<T> rhs) = delete;
	Array(const Array<T>&src) = delete;

	T getElementAt(size_t x) const;

	void setElementAt(size_t x, const T& val);

private:
	static const size_t kAllocSize = 4;
	void resize(size_t newSize);
	void initializedElements();
	T* mElems;
	size_t mSize;
};
