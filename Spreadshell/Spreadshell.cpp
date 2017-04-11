#include "Spreadshell.h"

int Spreadshell::sCounter;
Spreadshell::Spreadshell(int inWidth, int inHeight) :
    mWidth(inWidth <= kmaxWidth ? inWidth : kmaxWidth), 
    mHeight(inHeight <= kmaxHeight ? inHeight : kmaxHeight)
{
    mCells = new SpreadshellCell*[mWidth];
    for (int i = 0; i != mWidth; ++i) {
        mCells[i] = new SpreadshellCell[mHeight];
    }
}

void Spreadshell::setCellAt(int x, int y, const SpreadshellCell & cell)
{
    if (!inRange(x, mWidth) || !inRange(y, mWidth))
        throw std::out_of_range("");
    mCells[x][y] = cell;
}

Spreadshell::Spreadshell(const Spreadshell & src)
{
    mID = src.sCounter++;
    copyForm(src);
}

Spreadshell & Spreadshell::operator=(const Spreadshell & rhs)
{
    if (&rhs == this) {
        return *this;
    }
    this -> ~Spreadshell();
    copyForm(rhs);
    return *this;
}

SpreadshellCell & Spreadshell::getCellAt(int x, int y)
{
    if(!inRange(x,mWidth) || !inRange(y,mHeight))
        throw std::out_of_range("");
    return mCells[x][y];
}

int Spreadshell::getWidth()
{
    return mWidth;
}

int Spreadshell::getHeight()
{
    return mHeight;
}

int Spreadshell::getID()
{
    return mID;
    return 0;
}

Spreadshell::~Spreadshell()
{
    for (int i = 0; i != mWidth; i++) {
        delete[] mCells[i];
    }
    delete[] mCells;
    mCells = nullptr;
}

void Spreadshell::copyForm(const Spreadshell & src)
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

bool Spreadshell::inRange(int val, int upper)
{
    if (val <= upper)
        return true;
    else
        return false;
}
