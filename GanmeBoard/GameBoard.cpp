#include "GameBoard.h"






GameBoard::GameBoard(size_t inWidth, size_t inHeiget) :mWidth(inWidth), mHeight(inHeiget)
{
    initializedCellContainer();
}

GameBoard::GameBoard(const GameBoard & src)
{
    copyForm(src);
}

GameBoard::~GameBoard()
{
}

void GameBoard::copyForm(const GameBoard & src)
{
    mWidth = src.mWidth;
    mHeight = src.mHeight;
    initializedCellContainer();
    for (size_t i = 0; i != mWidth; ++i)
    {
        for (size_t j = 0; j != mHeight; ++j)
        {
            if (src.mCells[i][j])
            {
                mCells[i][j] = src.mCells[i][j]->clone();
            } 
            else
            {
                mCells[i][j].reset();
            }
        }
    }
}

void GameBoard::initializedCellContainer()
{
    mCells.resize(mWidth);
    for (auto& column : mCells)
    {
        column.resize(mHeight);
    }
}
