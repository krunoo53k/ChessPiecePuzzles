#include <string>

class ChessPiece
{
public:
    ChessPiece(const char &symbol) : symbol(symbol) {}
    virtual void FillBoardWithLegalMoves() = 0;
    char getSymbol()
    {
        return symbol;
    }

private:
    char symbol;
};

class Rook : ChessPiece
{
    public:
        Rook(char& symbol)
            :ChessPiece{symbol}
            {}
};