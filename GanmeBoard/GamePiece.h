//===============================================================
//Summary:
//          GamePiece ¿‡£¨ 
//FileName:
//          GamePiece.h
//Remarks:
//          ...
//Date:
//          2017/4/25
//Author:
//          ¡≥¡≥(kuliantnt@gmail.com)
//===============================================================
#pragma once
#include <memory>
class GamePiece
{
public:
	virtual ~GamePiece() = default;
	GamePiece() = default;
    virtual std::unique_ptr<GamePiece> clone()const = 0;
};

