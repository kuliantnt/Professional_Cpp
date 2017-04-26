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

template<typename T>
void Grid<T>::initializeCellsContainer()
{
    mCells.resize(mWidth);
    for (int i = 0; i != mCells.size(); ++i) {
        mCells[i].resize(mHeight);
    }
}

