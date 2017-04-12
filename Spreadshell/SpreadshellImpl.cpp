#include "SpreadshellImpl.h"

int SpreadshellImpl::sCounter;
SpreadshellImpl::SpreadshellImpl(const SpreadshellApplication& theApp, 
    int inWidth = kmaxWidth, int inHeight = kmaxHeight) :
    mTheApp(theApp),
    mWidth(inWidth <= kmaxWidth ? inWidth : kmaxWidth), 
    mHeight(inHeight <= kmaxHeight ? inHeight : kmaxHeight)
{
    mCells = new SpreadshellCell*[mWidth];
    for (int i = 0; i != mWidth; ++i) {
        mCells[i] = new SpreadshellCell[mHeight];
    }
}

void SpreadshellImpl::setCellAt(int x, int y, const SpreadshellCell & cell)
{
    if (!inRange(x, mWidth) || !inRange(y, mWidth))
        throw std::out_of_range("");
    mCells[x][y] = cell;
}

SpreadshellImpl::SpreadshellImpl(const SpreadshellImpl & src):
    mTheApp(src.mTheApp)
{
    mID = src.sCounter++;
    copyForm(src);
}

SpreadshellImpl & SpreadshellImpl::operator=(const SpreadshellImpl & rhs)
{
    if (&rhs == this) {
        return *this;
    }
    this -> ~SpreadshellImpl();
    copyForm(rhs);
    return *this;
}

SpreadshellCell & SpreadshellImpl::getCellAt(int x, int y) 
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
    for (int i = 0; i != mWidth; i++) {
        delete[] mCells[i];
    }
    delete[] mCells;
    mCells = nullptr;
}

void SpreadshellImpl::copyForm(const SpreadshellImpl & src)
{
    mHeight = src.mHeight;
    mWidth = src.mWidth;

    mCells = new SpreadshellCell*[mWidth];
    for (int i = 0; i != mWidth; ++i) {
        mCells[i] = new SpreadshellCell[mHeight];
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
