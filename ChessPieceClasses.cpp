#include <iostream>
#include <vector>
#include <string>

class ChessBoard;

using namespace std;

class ChessPiece
{
public:
    ChessPiece(const char &symbol) : symbol(symbol) {}
    virtual void FillBoardWithLegalMoves(ChessBoard *chessBoard, int size) = 0;
    char getSymbol()
    {
        return symbol;
    }
    void SetRow(int row)
    {
        locationX = row;
    }
    void SetColumn(int column)
    {
        locationY = column;
    }
    int getLocationX()
    {
        return locationX;
    }
    int getLocationY()
    {
        return locationY;
    }

private:
    char symbol;
    int locationX, locationY;
};

class ChessBoard
{
public:
    ChessBoard()
    {
        // Initialize the board with empty spaces
        for (int i = 0; i < 8; i++)
        {
            vector<ChessPiece *> row;
            for (int j = 0; j < 8; j++)
            {
                row.push_back(nullptr);
            }
            board.push_back(row);
        }
    }

    void SetPiece(int row, int col, ChessPiece *piece)
    {
        board[row][col] = piece;
    }

    void PrintBoard()
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j] == nullptr)
                {
                    cout << ".";
                }
                else
                {
                    cout << board[i][j]->getSymbol();
                }
            }
            cout << "\n";
        }
    }

    vector<vector<ChessPiece *>> GetBoard()
    {
        return board;
    }

private:
    vector<vector<ChessPiece *>> board;
};

class Rook : public ChessPiece
{
public:
    Rook(const char &symbol, int row, int column)
        : ChessPiece(symbol)
    {
        SetRow(row);
        SetColumn(column);
    }
void FillBoardWithLegalMoves(ChessBoard *chessBoard, int size) override //TODO: add size attribute in ChessBoard class
{
    int posX = getLocationX();
    int posY = getLocationY();
    auto board = chessBoard->GetBoard();

    // Add legal moves in row
    for (int i = 0; i < size; i++)
    {
        if (i != posY && (board[posX][i] == nullptr || board[posX][i]->getSymbol() == 'X'))
        {
            Rook *rook = new Rook('+', posX, i); //TODO: add a new class to specify attacked field
            rook->SetRow(posX);
            rook->SetColumn(i);
            chessBoard->SetPiece(posX, i, rook);
        }
    }

    // Add legal moves in column
    for (int i = 0; i < size; i++)
    {
        if (i != posX && (board[i][posY] == nullptr || board[i][posY]->getSymbol() == 'X'))
        {
            Rook *rook = new Rook('+', i, posY);
            rook->SetRow(i);
            rook->SetColumn(posY);
            chessBoard->SetPiece(i, posY, rook);
        }
    }
}


};