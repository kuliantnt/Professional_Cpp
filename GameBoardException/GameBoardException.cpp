#include "GameBoardException.h"
#include <new>
#include <stdexcept>


GameBoardExp::GameBoardExp(size_t inWidth, size_t inHeight)
    : mCells(nullptr), mWidth(inWidth), mHeight(inHeight)
{
    void allocateMemory();
}

GameBoardExp::GameBoardExp(const GameBoardExp& src)
{
    copyFrom(src);
}

GameBoardExp::~GameBoardExp()
{
    freeMemory();
}

void GameBoardExp::copyFrom(const GameBoardExp& src)
{
    mWidth = src.mWidth;
    mHeight = src.mHeight;
    allocateMemory();
    for (size_t i = 0; i != mHeight; i++)
    {
        for (size_t j = 0; j < mWidth; j++)
        {
            mCells[i][j] = src.mCells[i][j];
        }
    }
}

void GameBoardExp::freeMemory()
{
    for (size_t i = 0; i != mWidth; ++i)
    {
        delete[] mCells[i];
    }
    delete[] mCells;
    mCells = nullptr;
    mWidth = 0;
    mHeight = 0;
}

void GameBoardExp::allocateMemory()
{
    size_t i = 0;
    mCells = new GamePieceExp*[mWidth];
    try
    {
        for(i = 0; i < mWidth; i++)
        {
            mCells[i] = new GamePieceExp[mHeight];
        }
    }
    catch(...)
    {
        for(size_t j = 0; j < i; j++)
        {
            delete[] mCells[j];
        }
        delete[] mCells;
        mCells = nullptr;
        mWidth = 0;
        mHeight = 0;
        throw std::bad_alloc();
    }
}

GameBoardExp& GameBoardExp::operator=(const GameBoardExp&rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    freeMemory();
    copyFrom(rhs);
    return *this;
}

void GameBoardExp::setPieceAt(size_t x, size_t y, const GamePieceExp& inElem) const
{
    if (x >= mWidth)
        throw std::out_of_range("GameBorad::setPieceAt: x-coordinate beyond witdh");
    if (y >= mHeight)
        throw std::out_of_range("GameBoard::setPieceAt: y-coordinate beyond height");
    mCells[x][y] = inElem;
}

GamePieceExp& GameBoardExp::getPieceAt(size_t x, size_t y)
{
    return mCells[x][y];
}

const GamePieceExp& GameBoardExp::getPieceAt(size_t x, size_t y) const
{
    return mCells[x][y];
}

