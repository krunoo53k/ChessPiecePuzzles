#include <iostream>
#include "ChessPieceClasses.cpp"

int main()
{

    ChessPiece* chessBoard[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c",chessBoard[i][j]->getSymbol());
        }
        printf("\n");
    }

    return 0;
}