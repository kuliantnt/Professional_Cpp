#include "Grid_const_char.h"

Grid<const char*>::Grid(size_t inWidth, size_t inHeight) :mWidth(inWidth), mHeight(inHeight)
{
    initializeCellsContainer();
}

Grid<const char*>::~Grid()
{
    //NoThing
}

void Grid<const char*>::setElementAT(size_t x, size_t y, const char* inElem)
{
    if (inElem)
        mCells[x][y] = inElem;
    else
        mCells[x][y] = "";
}

const char* Grid<const char*>::getElementAt(size_t x, size_t y) const
{
    return mCells[x][y].c_str();
}

void Grid<const char*>::initializeCellsContainer()
{
    mCells.resize(mWidth);
    for (auto & colume : mCells)
    {
        colume.resize(mHeight);
    }
}
