#pragma once
#include <string>



template <typename T>
class AssociativeArray
{
public:
	AssociativeArray();
	virtual ~AssociativeArray();
	T& operator[] (const std::string& key);
	const T& operator[](const std::string& key) const;
private:
	std::pair <std::string, T> * m_element;
	static const size_t kAllocSize = 4;
	size_t m_size;
	size_t m_use_size; //使用过的元素
	void initialize_element();
	void resize(size_t new_size);

};


template <typename T>
AssociativeArray<T>::AssociativeArray()
{
	m_size = kAllocSize;
	m_element = new std::pair<std::string, T>[m_size];
	initialize_element();
}

template <typename T>
AssociativeArray<T>::~AssociativeArray()
{
	delete[] m_element;
	m_element = nullptr;
}

template <typename T>
T& AssociativeArray<T>::operator[](const std::string& key)
{
	if(m_use_size >= m_size)
	{
		resize(m_size + kAllocSize);
	}
	for(size_t i : m_size)
	{
		if(m_element[i].first == key)
		{
			return m_element[i].second;
		}
	}
	m_use_size++;
	m_element[m_use_size].first = key;
	return m_element[m_use_size].second;
}

template <typename T>
const T& AssociativeArray<T>::operator[](const std::string& key) const
{
	for (size_t i : m_size)
	{
		if (m_element[i].first == key)
		{
			return m_element[i].second;
		}
	}
	throw
		std::out_of_range("");
}

template <typename T>
void AssociativeArray<T>::initialize_element()
{
	for(auto i : m_size)
	{
		m_element[i] = std::pair<std::string, T>(std::string(), T());
	}
}

template <typename T>
void AssociativeArray<T>::resize(size_t new_size)
{
	size_t old_size = m_size;
	std::pair<std::string, T>* old_element = m_element;
	m_size = new_size;
	m_element = new std::pair<std::string, T>[m_size];
	initialize_element();
	for(size_t i : old_size)
	{
		m_element[i] = old_element[i];
	}
	delete[] old_element;
	old_element = nullptr;
}
