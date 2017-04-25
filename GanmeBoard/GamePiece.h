#pragma once
#include <memory>
class GamePiece
{
public:
    GamePiece();
    virtual std::unique_ptr<GamePiece> clone()const = 0;
    virtual ~GamePiece();
};

