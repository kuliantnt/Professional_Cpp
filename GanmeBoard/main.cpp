#include "GameBoard.h"
int main(int argc, char ** argv)
{
    GameBoard chessBoard(8, 8);
    auto pawn = std::make_unique<ChessPiece>();
    chessBoard.setPieceAt(0, 0, std::move(pawn));
    chessBoard.setPieceAt(0, 1, std::make_unique<ChessPiece>());
    chessBoard.setPieceAt(0, 1, nullptr);
}