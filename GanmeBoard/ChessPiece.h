#pragma once
#include "GamePiece.h"
class ChessPiece :
    public GamePiece
{
public:
    ChessPiece();
    virtual std::unique_ptr<GamePiece> clone() const override;
    virtual ~ChessPiece();
};

