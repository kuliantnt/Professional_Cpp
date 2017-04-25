//===============================================================
//Summary:
//          ChessPiece ¿‡£¨ 
//FileName:
//          ChessPiece.h
//Remarks:
//          ...
//Date:
//          2017/4/25
//Author:
//          ¡≥¡≥(kuliantnt@gmail.com)
//===============================================================
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

