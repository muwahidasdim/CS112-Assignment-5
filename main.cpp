#include <iostream>
using namespace std;

class Piece
{
    char player;
    int column, row;
    bool isKing;

    
public:
    Piece() {}
    Piece(char player, int row, int column, bool isKing = false)
    {
        this->player = player;
        this->column = column;
        this->row = row;
        this->isKing = isKing;
    }
    int getrow()
    {
        return row;
    }
    int getcolumn()
    {
        return column;
    }

};

class Position
{
    bool isDark, isKingMaker;
    char containingValue;

public:
    Position() {}
    Position(bool isDark, int row)
    {
        this->isDark = isDark;
        containingValue = ' ';

        if (row == 0 || row == 7)
            isKingMaker = true;
        else
            isKingMaker = false;
    }

    void setContainingValue(char x)
    {
        containingValue = x;
    }

    char getContainingValue()
    {
        return containingValue;
    }

    bool getIsKingMaker()
    {
        return isKingMaker;
    }

    bool getIsDark()
    {
        return isDark;
    }

};

void game_init(char board[8][8]);
void board_init(Position board[8][8]);
void player_init(Piece[], Position board[8][8], char);
void renderBoard(Position board[8][8]);
void theGame();
void playeronemoves(Piece red_pieces[12], Position board[8][8]);

int main()
{
    theGame();

    return 0;
}

void board_init(Position board[8][8])
{
    bool isLastDark = false;
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if (!isLastDark)
            {
                board[row][col] = Position(true, row);
                if (col != 7)
                    isLastDark = true;
            }
            else
            {
                board[row][col] = Position(false, row);
                if (col != 7)
                    isLastDark = false;
            }

        }
    }
}

void player_init(Piece pieces[], Position board[8][8], char player)
{
    int piece_index = 0, max_row, row;

    if (player == 'R')
    {
        row = 0;
        max_row = 3;
    }

    else
    {
        row = 5;
        max_row = 8;
    }

    for (; row < max_row; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if (board[row][col].getIsDark())
            {
                pieces[piece_index] = Piece(player, row, col);
                board[row][col].setContainingValue(player);
                piece_index++;
            }
        }
    }
}

void theGame()
{
    Position board[8][8];
    Piece red_pieces[12], white_pieces[12];
    bool gameCompelete = false, isPlayerOne = true;

    board_init(board);
    player_init(red_pieces, board, 'R');
    player_init(white_pieces, board, 'W');

    while (!gameCompelete)
    {
        if (isPlayerOne)
        {
            renderBoard(board);
            playeronemoves(red_pieces, board);
            gameCompelete = true;
            renderBoard(board);
        }

        else
        {
            // To Be continued
        }
    }
}

void renderBoard(Position board[8][8])
{
    for (int i = 0; i < 11; i++)
        cout << "---";

    cout << endl;
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if (col == 0)
            {
                cout << "| " << board[row][col].getContainingValue() << " | ";
            }
            else
            {
                cout << board[row][col].getContainingValue() << " | ";
            }
        }

        cout << endl;
        for (int i = 0; i < 11; i++)
            cout << "---";
        cout << endl;
    }
}
void playeronemoves(Piece red_pieces[12], Position board[8][8])
{   
    int move_choice = 48; // AscII encoding of 0;
    for (int i = 0;i < 12;i++)
    {
        
        if (board[red_pieces[i].getrow() + 1][red_pieces[i].getcolumn() + 1].getContainingValue() ==' ' && (red_pieces[i].getcolumn()+1)<8 && (red_pieces[i].getrow() + 1)<8)
        {   
            move_choice++;
            board[red_pieces[i].getrow() + 1][red_pieces[i].getcolumn() + 1].setContainingValue(move_choice);
            
            cout <<  "Possible Option:  row:" << red_pieces[i].getrow() + 1 << "  column:  " << red_pieces[i].getcolumn() + 1<<endl;
            
        }
        if (board[red_pieces[i].getrow() + 1][red_pieces[i].getcolumn() - 1].getContainingValue() ==' ' && (red_pieces[i].getcolumn()-1) >=0 && (red_pieces[i].getrow() + 1) <8)
        {
            move_choice++;
            board[red_pieces[i].getrow() + 1][red_pieces[i].getcolumn() - 1].setContainingValue(move_choice);
            cout<< "Possible Option:  row:" << red_pieces[i].getrow() + 1 << "  column:  " << red_pieces[i].getcolumn() - 1<<endl;
            

        }
       
    }


}
