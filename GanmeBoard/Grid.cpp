#include "Grid.h"

template<typename T>
Grid<T>::Grid(size_t inWidth, size_t inHeight) : mWidth(inWidth), mHeight(inHeight)
{
    initializeCellsContainer();
}

template<typename T>
Grid<T>::~Grid()
{
}

template <typename T>
template <typename E>
Grid<T>::Grid(const Grid<E>& src)
{
    copyFrom(src);
}

template <typename T>
template <typename E>
Grid<T>& Grid<T>::operator=(const Grid<E>& rhs)
{
    copyFrom(rhs);
    return *this;
}

template<typename T>
void Grid<T>::setElementAt(size_t x, size_t y, const T & inElem)
{
    mCells[x][y] = inElem;
}

template<typename T>
T & Grid<T>::getElementAt(size_t x, size_t y)
{
    return mCells[x][y];
}

template<typename T>
const T & Grid<T>::getElementAt(size_t x, size_t y) const
{
    return mCells[x][y];
}

template <typename T>
template <typename E>
void Grid<T>::copyFrom(const Grid<E>& src)
{
    mWidth = src.getWidth();
    mHeight = src.getHeight();
    initializeCellsContainer();
    for (size_t i = 0; i < mWidth; i++)
    {
        for (size_t j = 0; j != mHeight; j++)
        {
            mCells[i][j] = src.getElementAt(i, j);
        }
    }
}

template<typename T>
void Grid<T>::initializeCellsContainer()
{
    mCells.resize(mWidth);
    for (int i = 0; i != mCells.size(); ++i) {
        mCells[i].resize(mHeight);
    }
}

