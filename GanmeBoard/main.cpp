#include "GameBoard.h"
#include "ChessPiece.h"
int main(int argc, char ** argv)
{
    GameBoard<ChessPiece> chessBoard(8, 8);
    ChessPiece pawn;
    chessBoard.setElementAt(0, 0, pawn);
    chessBoard.move(0, 0, 0, 1);
    //Grid<ChessPiece> chessBoard(8, 8);
    //ChessPiece pawn;
    //chessBoard.setElementAt(1, 1, pawn);
}