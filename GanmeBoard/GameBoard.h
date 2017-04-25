#pragma once
#include "ChessPiece.h"
class GameBoard
{
public:
    explicit GameBoard(size_t inWidth = kDefaultWidth, size_t inHeiget = kDefaultHeiget);
    virtual ~GameBoard();
    static const size_t kDefaultWidth = 10;
    static const size_t kDefaultHeiget= 10;
};

