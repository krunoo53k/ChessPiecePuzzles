#include <iostream>
#include "ChessPieceClasses.cpp"

int main()
{
    ChessBoard board;
    Rook rook('R', 1, 2);
    board.SetPiece(1, 2, &rook);
    board.PrintBoard();
    cout<<"\n";
    rook.FillBoardWithLegalMoves(&board, 8);
    board.PrintBoard();
    return 0;
}