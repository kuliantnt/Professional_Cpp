#include "GameBoard.h"


GameBoard::GameBoard(size_t inWidth, size_t inHeiget) : mWidth(inWidth), mHeight(inHeiget)
{
    initializedCellContainer();
}

GameBoard::GameBoard(const GameBoard& src)
{
    copyForm(src);
}

GameBoard& GameBoard::operator=(const GameBoard& rhs)
{
    if (this != &rhs)
        return *this;
    copyForm(rhs);
    return *this;
}

GameBoard::~GameBoard()
{
}

void GameBoard::setPieceAt(size_t x, size_t y, std::unique_ptr<GamePiece> inPiece)
{
    mCells[x][y] = move(inPiece);
}

std::unique_ptr<GamePiece>& GameBoard::getpriceAt(size_t x, size_t y)
{
    return mCells[x][y];
}

const std::unique_ptr<GamePiece>& GameBoard::getpriceAt(size_t x, size_t y) const
{
    return mCells[x][y];
}

size_t GameBoard::getHeight() const
{
    return mHeight;
}

void GameBoard::copyForm(const GameBoard& src)
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
