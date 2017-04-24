//===============================================================
//Summary:
//          SpreadshellImpl ¿‡£¨ 
//FileName:
//          SpreadshellImpl.cpp
//Remarks:
//          ...
//Date:
//          2017/4/12
//Author:
//          ¡≥¡≥(kuliantnt@gmail.com)
//===============================================================
#include "SpreadshellImpl.h"

int SpreadshellImpl::sCounter;
SpreadshellImpl::SpreadshellImpl(const SpreadshellApplication& theApp, 
    int inWidth , int inHeight ) :
    mWidth(inWidth <= kmaxWidth ? inWidth : kmaxWidth), 
    mHeight(inHeight <= kmaxHeight ? inHeight : kmaxHeight)
{
    mCells = new SpreadshellCell_old*[mWidth];
    for (int i = 0; i != mWidth; ++i) {
        mCells[i] = new SpreadshellCell_old[mHeight];
    }
}

void SpreadshellImpl::setCellAt(int x, int y, const SpreadshellCell_old & cell)
{
    if (!inRange(x, mWidth) || !inRange(y, mWidth))
        throw std::out_of_range("");
    mCells[x][y] = cell;
}

SpreadshellImpl::SpreadshellImpl(const SpreadshellImpl & src)
{
    mID = src.sCounter++;
    copyForm(src);
}

SpreadshellImpl::SpreadshellImpl(SpreadshellImpl && src) noexcept
{
    mWidth = src.mWidth;
    mHeight = src.mHeight;
    mCells = src.mCells;
    src.mWidth = 0;
    src.mHeight = 0;
    src.mCells = nullptr;
}

SpreadshellImpl & SpreadshellImpl::operator=(const SpreadshellImpl & rhs)
{
    if (&rhs == this) {
        return *this;
    }
    freeMemory();
    copyForm(rhs);
    return *this;
}

SpreadshellImpl & SpreadshellImpl::operator=(SpreadshellImpl && rhs) noexcept
{
    if (this == &rhs)
        return *this;
    freeMemory();
    mWidth = rhs.mWidth;
    mHeight = rhs.mHeight;
    mCells = rhs.mCells;

    rhs.mCells = nullptr;
    rhs.mWidth = 0;
    rhs.mHeight = 0;
    return *this;
}

SpreadshellCell_old & SpreadshellImpl::getCellAt(int x, int y) 
{
    if(!inRange(x,mWidth) || !inRange(y,mHeight))
        throw std::out_of_range("");
    return mCells[x][y];
}

int SpreadshellImpl::getWidth() const
{
    return mWidth;
}

int SpreadshellImpl::getHeight()const
{
    return mHeight;
}

int SpreadshellImpl::getID()const
{
    return mID;
    return 0;
}

SpreadshellImpl::~SpreadshellImpl()
{
    freeMemory();
}

void SpreadshellImpl::copyForm(const SpreadshellImpl & src)
{
    mHeight = src.mHeight;
    mWidth = src.mWidth;

    mCells = new SpreadshellCell_old*[mWidth];
    for (int i = 0; i != mWidth; ++i) {
        mCells[i] = new SpreadshellCell_old[mHeight];
    }
    for (int i = 0; i != mWidth; ++i) {
        for (int j = 0; j != mHeight; ++j) {
            mCells[i][j] = src.mCells[i][j];
        }
    }
}

bool SpreadshellImpl::inRange(int val, int upper)
{
    if (val <= upper)
        return true;
    else
        return false;
}

void SpreadshellImpl::freeMemory()
{
    for (int i = 0; i != mWidth; i++) {
        delete[] mCells[i];
    }
    delete[] mCells;
    mCells = nullptr;
}
