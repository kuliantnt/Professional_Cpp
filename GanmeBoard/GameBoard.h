//===============================================================
//Summary:
//          GameBoard ¿‡£¨ 
//FileName:
//          GameBoard.h
//Remarks:
//          ...
//Date:
//          2017/4/25
//Author:
//          ¡≥¡≥(kuliantnt@gmail.com)
//===============================================================
#pragma once
#include <vector>
#include "ChessPiece.h"
class GameBoard
{
public:
    explicit GameBoard(size_t inWidth = kDefaultWidth, size_t inHeiget = kDefaultHeiget);
    GameBoard(const GameBoard& src);
    GameBoard& operator= (const GameBoard&rhs);
    virtual ~GameBoard();
    void setPieceAt(size_t x, size_t y, std::unique_ptr<GamePiece> inPiece);
    std::unique_ptr<GamePiece>& getpriceAt(size_t x, size_t y) ;
    const std::unique_ptr<GamePiece>& getpriceAt(size_t x, size_t y) const;
    size_t getHeight() const { return mHeight; }
    size_t getWidth() const { return mWidth; }
    static const size_t kDefaultWidth = 10;
    static const size_t kDefaultHeiget= 10;
private:
    void copyForm(const GameBoard& src);
    void initializedCellContainer();
    std::vector<std::vector<std::unique_ptr<GamePiece>>> mCells;
    size_t mWidth, mHeight;
};

