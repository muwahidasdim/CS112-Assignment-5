#include <iostream>
using namespace std;
class Position;
class Piece
{
    char player;
    int column, row;
    bool isKing;


public:
    static int move_choice;
    static bool inJump;
    Piece() {}
    Piece(char player, int row, int column, bool isKing = false)
    {
        this->player = player;
        this->column = column;
        this->row = row;
        this->isKing = isKing;
    }
    void setrow(int x)
    {
        row = x;
    }
    void setcolumn(int y)
    {
        column = y;
    }
    int getrow()
    {
        return row;
    }
    int getcolumn()
    {
        return column;
    }

    void setIsKing()
    {
        isKing = true; 
    }
    bool getIsKing()
    {
        return isKing;
    }

    void validateMoves(Position board[8][8]);
    void makeMove(int row, int col)
    {
        this -> row = row;
        this -> column = col;

        if(row == 0 && player == 'W')
            isKing = true;
        else if(row == 7 && player == 'R')
            isKing = true;
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
       this-> containingValue = x ;
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


    void afterMoveCleaner()
    {
        if(containingValue != 'R' && containingValue != 'W')
            containingValue = ' ';
    }

};

void Piece::validateMoves(Position board[8][8])
{

    // int move_choice = 48; // AscII encoding of 0;
    if(player == 'R')
    {
        if(!isKing)
        {   
            if (board[row + 1][column + 1].getContainingValue() == 'W')
            {
                if((board[row + 2][column + 2].getContainingValue() == ' ' || (board[row + 2][column + 2].getContainingValue() != 'W' && board[row + 2][column + 2].getContainingValue() != player)) && (column + 2 < 8) && (row + 2 < 8))
                {
                    move_choice++;
                    board[row + 2][column + 2].setContainingValue(move_choice);
                    inJump = true;
                }
            }
            if ((board[row + 1][column - 1].getContainingValue() == 'W') && (column - 1 >= 0) && (row + 1 < 8))
            {
                if((board[row + 2][column - 2].getContainingValue() == ' ' || (board[row + 2][column - 2].getContainingValue() != 'W' && board[row + 2][column - 2].getContainingValue() != player)) && (column - 2 >= 0) && (row + 2 < 8))
                {
                    move_choice++;
                    board[row + 2][column - 2].setContainingValue(move_choice);
                    inJump = true;
                }
            }
            if(!inJump)
            {
                if ((board[row + 1][column + 1].getContainingValue() == ' ') && (column + 1 < 8) && (row + 1 < 8))
                {
                    move_choice++;
                    board[row + 1][column + 1].setContainingValue(move_choice);
                }
                if (board[row + 1][column - 1].getContainingValue() == ' ' && (column - 1) >= 0 && (row + 1) < 8)
                {
                    move_choice++;
                    board[row + 1][column - 1].setContainingValue(move_choice);
                }
            }
      

            

        }

        else
        {
            if (board[row + 1][column + 1].getContainingValue() == 'W' && (column + 1 < 8) && (row + 1 < 8))
            {
                if((board[row + 2][column + 2].getContainingValue() == ' ' || (board[row + 2][column + 2].getContainingValue() != 'W' && board[row + 2][column + 2].getContainingValue() != player)) && (column + 2 < 8) && (row + 2 < 8))
                {
                    move_choice++;
                    board[row + 2][column + 2].setContainingValue(move_choice);
                    inJump = true;
                }
            }
            if((board[row + 1][column].getContainingValue() == 'W') && (row + 1 < 8))
            {
                if((board[row + 2][column].getContainingValue() == ' ' || (board[row + 2][column].getContainingValue() != 'W' && board[row + 2][column].getContainingValue() != player)) && (row + 2 < 8))
                {
                    move_choice++;
                    board[row + 2][column].setContainingValue(move_choice);
                    inJump = true;
                }

            }

            if ((board[row + 1][column - 1].getContainingValue() == 'W') && (column - 1 >= 0) && (row + 1 < 8))
            {
                if((board[row + 2][column - 2].getContainingValue() == ' ' || (board[row + 2][column - 2].getContainingValue() != 'W' && board[row + 2][column - 2].getContainingValue() != player)) && (column - 2 >= 0) && (row + 2 < 8))
                {
                    move_choice++;
                    board[row + 2][column - 2].setContainingValue(move_choice);
                    inJump = true;
                }
            }
            if (board[row - 1][column + 1].getContainingValue() == 'W' && (column + 1 < 8) && (row - 1 >= 0))
            {
                if((board[row - 2][column + 2].getContainingValue() == ' ' || (board[row - 2][column + 2].getContainingValue() != 'W' && board[row - 2][column + 2].getContainingValue() != player)) && (column + 2 < 8) && (row - 2 >= 0))
                {
                    move_choice++;
                    board[row - 2][column + 2].setContainingValue(move_choice);
                    inJump = true;
                }
            }
            if((board[row - 1][column].getContainingValue() == 'W') && (row - 1 >= 0))
            {
                if((board[row - 2][column].getContainingValue() == ' ' || (board[row - 2][column].getContainingValue() != 'W' && board[row - 2][column].getContainingValue() != player)) && (row - 2 >= 0))
                {
                    move_choice++;
                    board[row - 2][column].setContainingValue(move_choice);
                    inJump = true;
                }

            }

            if ((board[row - 1][column - 1].getContainingValue() == 'W') && (column - 1 >= 0) && (row - 1 >= 0))
            {
                if((board[row - 2][column - 2].getContainingValue() == ' ' || (board[row - 2][column - 2].getContainingValue() != 'W' && board[row - 2][column - 2].getContainingValue() != player)) && (column - 2 >= 0) && (row - 2 >= 0))
                {
                    move_choice++;
                    board[row - 2][column - 2].setContainingValue(move_choice);
                    inJump = true;
                }
            }


            if(!inJump)
                if (board[row + 1][column - 1].getContainingValue() == ' ' && (column - 1 >= 0) && (row + 1) < 8)
                {
                    move_choice++;
                    board[row + 1][column - 1].setContainingValue(move_choice);
                }
                if(board[row + 1][column].getContainingValue() == ' ' && (row + 1 < 8))
                {
                    move_choice++;
                    board[row + 1][column].setContainingValue(move_choice);
                }
                if ((board[row + 1][column + 1].getContainingValue() == ' ') && (column + 1 < 8) && (row + 1 < 8))
                {
                    move_choice++;
                    board[row + 1][column + 1].setContainingValue(move_choice);
                }
                if ((board[row - 1][column + 1].getContainingValue() == ' ') && (column + 1 < 8) && (row - 1 >= 0))
                {
                    move_choice++;
                    board[row - 1][column + 1].setContainingValue(move_choice);
                }
                if(board[row - 1][column].getContainingValue() == ' ' && (row - 1 >= 0))
                {
                    move_choice++;
                    board[row - 1][column].setContainingValue(move_choice);
                }
                if ((board[row - 1][column - 1].getContainingValue() == ' ') && (column - 1 >= 0) && (row - 1 >= 0))
                {
                    move_choice++;
                    board[row - 1][column - 1].setContainingValue(move_choice);
                }

        }
    }
    else
    {
        if(!isKing)
        {   
            if (board[row - 1][column + 1].getContainingValue() == 'R')
            {
                if((board[row - 2][column + 2].getContainingValue() == ' ' || (board[row - 2][column + 2].getContainingValue() != 'R' && board[row - 2][column + 2].getContainingValue() != player)) && (column + 2 < 8) && (row - 2 >= 0))
                {   
                    cout << "THE FIRST CALLED\n";
                    move_choice++;
                    board[row - 2][column + 2].setContainingValue(move_choice);
                    inJump = true;
                }
            }
            if ((board[row - 1][column - 1].getContainingValue() == 'R') && (column - 1 >= 0) && (row - 1 >= 0))
            {
                if((board[row - 2][column - 2].getContainingValue() == ' ' || (board[row - 2][column - 2].getContainingValue() != 'R' && board[row - 2][column - 2].getContainingValue() != player)) && (column - 2 >= 0) && (row - 2 >= 0))
                {
                    cout << "THE SECOND CALLED\n";
                    move_choice++;
                    board[row - 2][column - 2].setContainingValue(move_choice);
                    inJump = true;
                }
            }
            if(!inJump)
            {
                if ((board[row - 1][column + 1].getContainingValue() == ' ') && (column + 1 < 8) && (row - 1 >= 0))
                {
                    move_choice++;
                    board[row - 1][column + 1].setContainingValue(move_choice);
                }
                if (board[row - 1][column - 1].getContainingValue() == ' ' && (column - 1) >= 0 && (row - 1) < 8)
                {
                    move_choice++;
                    board[row - 1][column - 1].setContainingValue(move_choice);
                }
            }
      
        }
/*
        else
        {

            if (board[row - 1][column - 1].getContainingValue() == ' ' && (column - 1 >= 0) && (row - 1 >= 0))
            {
                move_choice++;
                board[row - 1][column - 1].setContainingValue(move_choice);
            }
            if(board[row - 1][column].getContainingValue() == ' ' && (row - 1 >= 0))
            {
                move_choice++;
                board[row - 1][column].setContainingValue(move_choice);
            }
    
            if ((board[row - 1][column + 1].getContainingValue() == ' ') && (column + 1 < 8) && (row - 1 >= 0))
            {
                move_choice++;
                board[row - 1][column + 1].setContainingValue(move_choice);
            }
        }*/
    }
    
    
            
}



int Piece::move_choice = 48;
bool Piece::inJump = false;
int numOfReds = 12, numOfWhites = 12;

void game_init(char board[8][8]);
void board_init(Position board[8][8]);
void player_init(Piece[], Position board[8][8], char);
void renderBoard(Position board[8][8]);
void theGame();
void playeronemoves(Piece red_pieces[12], Position board[8][8]);
void makeMove(Piece *&, Piece *&, Position board[8][8], char);
int indexFinder(Piece *&, char, int, int);
void positionUpdater(Piece *&, Position board[8][8], char, int, int, int);
void makeJump(Piece *&, Piece *&, Position board[8][8], char,int, int, int);
void afterMoveCleaner(Position board[8][8]);
void modifyPieces(Piece *&, int, char);

int main()
{
    theGame();
    int s = 13;
    int x = s % 10;
    s/=10;
    cout << s;

    return 0;
}

void afterMoveCleaner(Position board[8][8])
{   
    char x;
    for(int row = 0; row < 8; row++)
    {
        for(int col = 0; col < 8; col++)
        {
            x = board[row][col].getContainingValue();
            if((x != Piece::move_choice) && (x != 'R') && (x != 'W'))
            {
                board[row][col].setContainingValue(' ');
            }
        }
    }
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
    bool gameCompelete = false, isPlayerOne = true, jumpChecked = false;
    Piece *red_pieces = new Piece[numOfReds];
    Piece *white_pieces = new Piece[numOfWhites];

    board_init(board);
    player_init(red_pieces, board, 'R');
    player_init(white_pieces, board, 'W');
   red_pieces[9].setIsKing();
    renderBoard(board);
    while (!gameCompelete)
    {   
        if (isPlayerOne)
        {

            cout << endl << "Red: " << numOfReds << endl;
            for(int i = 0; i < numOfReds; i++)
            {
                red_pieces[i].validateMoves(board);
                if(Piece::inJump && !jumpChecked)
                {
                    afterMoveCleaner(board);
                    jumpChecked = true;
                }

            }
            Piece::move_choice = 48;
            renderBoard(board);
            makeMove(red_pieces, white_pieces, board, 'R');
            renderBoard(board);
            jumpChecked = false;
            isPlayerOne = false;

        }

        else
        {
            cout << endl << "White: " << numOfWhites << endl;
            for(int i = 0; i < numOfWhites; i++)
            {
                white_pieces[i].validateMoves(board);
                if(Piece::inJump && !jumpChecked)
                {
                    afterMoveCleaner(board);
                    jumpChecked = true;
                }
            }
            Piece::move_choice = 48;
            renderBoard(board);
            makeMove(red_pieces, white_pieces, board, 'W');
            renderBoard(board);
            isPlayerOne = true;
            jumpChecked = false;
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
    Piece Move[36];
    Piece old[36];
   
    int move_choice = 48; // AscII encoding of 0;
    int c = 0;
    for (int i = 0;i < 12;i++)
    {
        
        if (board[red_pieces[i].getrow() + 1][red_pieces[i].getcolumn() + 1].getContainingValue() == ' ' && (red_pieces[i].getcolumn() + 1) < 8 && (red_pieces[i].getrow() + 1) < 8)
        {
            
     
            move_choice++;
            c++;
            board[red_pieces[i].getrow() + 1][red_pieces[i].getcolumn() + 1].setContainingValue(move_choice);
            cout << "Possible Option:  row:" << red_pieces[i].getrow() + 1 << "  column:  " << red_pieces[i].getcolumn() + 1 << endl;
            old[c].setrow(red_pieces[i].getrow()) ;
            old[c].setcolumn(red_pieces[i].getcolumn()) ;
            Move[c].setrow(red_pieces[i].getrow() + 1)  ;
            Move[c].setcolumn(red_pieces[i].getcolumn() + 1)  ;
        }
        if (board[red_pieces[i].getrow() + 1][red_pieces[i].getcolumn() - 1].getContainingValue() == ' ' && (red_pieces[i].getcolumn() - 1) >= 0 && (red_pieces[i].getrow() + 1) < 8)
        {
            move_choice++;
            c++;
            board[red_pieces[i].getrow() + 1][red_pieces[i].getcolumn() - 1].setContainingValue(move_choice);
            cout << "Possible Option:  row:" << red_pieces[i].getrow() + 1 << "  column:  " << red_pieces[i].getcolumn() - 1 << endl;
            old[c].setrow(red_pieces[i].getrow())  ;
            old[c].setcolumn(red_pieces[i].getcolumn())  ;
            Move[c].setrow(red_pieces[i].getrow() + 1) ;
            Move[c].setcolumn(red_pieces[i].getcolumn() - 1) ;
        }
    }
    renderBoard(board);
    int option;
    cout << "Enter where you want to move:  ";
    cin >> option;
    int total = c;
            board[old[option].getrow()][old[option].getcolumn()].setContainingValue(' ');
            board[Move[option].getrow()][Move[option].getcolumn()].setContainingValue('R');
            
           

    }

void makeMove(Piece *&red_pieces, Piece *&white_pieces, Position board[8][8], char player)
{
    int choice, piece_checker = 0, index;
    cout << "Enter the number corresponding to your choice. If there are two possible moves with the same digit, enter an extra 1 or 2 depending on whether you want to move the 1st piece or the second from left: ";
    cin >> choice, cout << endl;
    if(choice > 10)
    {
        piece_checker = choice % 10;
        choice/=10;
    }


    for(int row = 0; row < 8; row++)
    {
        for(int col = 0; col < 8; col++)
        {
            if(board[row][col].getContainingValue() == choice + '0')
            {
                if(!Piece::inJump)
                {
                    board[row][col].setContainingValue(player);
                    if(player == 'R')
                        positionUpdater(red_pieces, board, player, piece_checker, row, col);
                    else
                        positionUpdater(white_pieces, board, player, piece_checker, row, col);

                    continue;
                }
                else
                {
                    board[row][col].setContainingValue(player);
                    makeJump(red_pieces, white_pieces, board, player, piece_checker, row, col);
                    continue;
                }
                
            }
            else
                board[row][col].afterMoveCleaner();
        }
    }
    
}

int indexFinder(Piece *&pieces, char player,int row, int col)
{
    int size;
    if(player == 'R')
        size = numOfReds;
    else
        size = numOfWhites;

    for(int i = 0; i < size; i++)
    {
        if(pieces[i].getrow() == row && pieces[i].getcolumn() == col)
            return i;
    }
    
}

void positionUpdater(Piece *&pieces, Position board[8][8], char player, int piece_selector, int row, int col)
{
    int index;
    if(player == 'R')
    {
        switch (piece_selector)
        {
        case 1:
            if(board[row - 1][col - 1].getContainingValue() == player)
            {
                index = indexFinder(pieces, player, row - 1, col - 1);
                pieces[index].makeMove(row, col);
                board[row - 1][col - 1].setContainingValue(' ');
            }
            else if(board[row - 1][col].getContainingValue() == player)
            {
                index = indexFinder(pieces, player, row - 1, col);
                if(pieces[index].getIsKing())
                {
                    pieces[index].makeMove(row, col);
                    board[row - 1][col].setContainingValue(' ');
                }
                else if(board[row - 1][col + 1].getContainingValue() == player)
                {
                    index = indexFinder(pieces, player, row - 1, col + 1);
                    pieces[index].makeMove(row, col);
                    board[row - 1][col + 1].setContainingValue(' ');
                }
                else
                {
                    board[row][col].setContainingValue(' ');
                    cout << "Invalid choice!\n";
                }
                
            }

            else if(board[row - 1][col + 1].getContainingValue() == player)
            {
                index = indexFinder(pieces, player, row - 1, col + 1);
                pieces[index].makeMove(row, col);
                board[row - 1][col + 1].setContainingValue(' ');
            }
            else
            {
                board[row][col].setContainingValue(' ');
                cout << "Invalid choice!\n";
            }
            break;
            

        case 2:
            
            if(board[row - 1][col - 1].getContainingValue() == player && board[row - 1][col].getContainingValue() == player)
            {
                index = indexFinder(pieces, player, row - 1, col);
                if(pieces[index].getIsKing())
                {
                    pieces[index].makeMove(row, col);
                    board[row - 1][col].setContainingValue(' ');
                }
                else if(board[row - 1][col - 1].getContainingValue() == player && board[row - 1][col + 1].getContainingValue() == player)
                {
                    index = indexFinder(pieces, player, row - 1, col + 1);
                    pieces[index].makeMove(row, col);
                    board[row - 1][col + 1].setContainingValue(' ');
                }
                else
                {
                    board[row][col].setContainingValue(' ');
                    cout << "Invalid choice!\n";
                }
            }
            else if(board[row - 1][col - 1].getContainingValue() == player && board[row - 1][col + 1].getContainingValue() == player)
            {
                index = indexFinder(pieces, player, row - 1, col + 1);
                pieces[index].makeMove(row, col);
                board[row - 1][col + 1].setContainingValue(' ');
            }
            else if(board[row - 1][col].getContainingValue() == player && board[row - 1][col + 1].getContainingValue() == player)
            {
                index = indexFinder(pieces, player, row - 1, col + 1);
                pieces[index].makeMove(row, col);
                board[row - 1][col + 1].setContainingValue(' ');
            }
            else
            {
                board[row][col].setContainingValue(' ');
                cout << "Invalid choice!\n";
            }

            break;
    /*
        case 3:
            index = indexFinder(pieces, player, row - 1, col + 1);
            board[row - 1][col + 1].setContainingValue(' ');
            pieces[index].makeMove(row - 1, col + 1);
            break;*/
        default:
            board[row][col].setContainingValue(' ');
            cout << "Invalid choice!\n";
            break;
        }
    }
    else
    {
        switch (piece_selector)
        {
        case 1:
            if(board[row + 1][col - 1].getContainingValue() == player)
            {
                index = indexFinder(pieces, player, row + 1, col - 1);
                pieces[index].makeMove(row, col);
                board[row + 1][col - 1].setContainingValue(' ');
            }
            else if(board[row + 1][col].getContainingValue() == player)
            {
                index = indexFinder(pieces, player, row + 1, col);
                if(pieces[index].getIsKing())
                {
                    pieces[index].makeMove(row, col);
                    board[row + 1][col].setContainingValue(' ');
                }
                else if(board[row + 1][col + 1].getContainingValue() == player)
                {
                    index = indexFinder(pieces, player, row + 1, col + 1);
                    pieces[index].makeMove(row, col);
                    board[row + 1][col + 1].setContainingValue(' ');
                }
                else
                {
                    board[row][col].setContainingValue(' ');
                    cout << "Invalid choice!\n";
                }
                
            }

            else if(board[row + 1][col + 1].getContainingValue() == player)
            {
                index = indexFinder(pieces, player, row + 1, col + 1);
                pieces[index].makeMove(row, col);
                board[row + 1][col + 1].setContainingValue(' ');
            }
            else
            {
                board[row][col].setContainingValue(' ');
                cout << "Invalid choice!\n";
            }
            break;
            

        case 2:
            
            if(board[row + 1][col - 1].getContainingValue() == player && board[row + 1][col].getContainingValue() == player)
            {
                index = indexFinder(pieces, player, row + 1, col);
                if(pieces[index].getIsKing())
                {
                    pieces[index].makeMove(row, col);
                    board[row + 1][col].setContainingValue(' ');
                }
                else if(board[row + 1][col - 1].getContainingValue() == player && board[row + 1][col + 1].getContainingValue() == player)
                {
                    index = indexFinder(pieces, player, row + 1, col + 1);
                    pieces[index].makeMove(row, col);
                    board[row + 1][col + 1].setContainingValue(' ');
                }
                else
                {
                    board[row][col].setContainingValue(' ');
                    cout << "Invalid choice!\n";
                }
            }
            else if(board[row + 1][col - 1].getContainingValue() == player && board[row + 1][col + 1].getContainingValue() == player)
            {
                index = indexFinder(pieces, player, row + 1, col + 1);
                pieces[index].makeMove(row, col);
                board[row + 1][col + 1].setContainingValue(' ');
            }
            else if(board[row + 1][col].getContainingValue() == player && board[row + 1][col + 1].getContainingValue() == player)
            {
                index = indexFinder(pieces, player, row + 1, col + 1);
                pieces[index].makeMove(row, col);
                board[row + 1][col + 1].setContainingValue(' ');
            }
            else
            {
                board[row][col].setContainingValue(' ');
                cout << "Invalid choice!\n";
            }

            break;
    /*
        case 3:
            index = indexFinder(pieces, player, row + 1, col + 1);
            board[row + 1][col + 1].setContainingValue(' ');
            pieces[index].makeMove(row + 1, col + 1);
            break;*/
        default:
            board[row][col].setContainingValue(' ');
            cout << "Invalid choice!\n";
            break;
        }        
    }
    
}

void makeJump(Piece *&red_pieces, Piece *&white_pieces, Position board[8][8], char player, int piece_selector, int row, int col)
{
    int index;
    if(player == 'R')
    {
        switch (piece_selector)
        {
        case 1:
            if(board[row - 1][col - 1].getContainingValue() == 'W')
            {
                index = indexFinder(red_pieces, player, row - 2, col - 2);
                red_pieces[index].makeMove(row, col);
                index = indexFinder(white_pieces, 'W', row - 1, col - 1);
                modifyPieces(white_pieces, index, 'W');
                board[row - 2][col - 2].setContainingValue(' ');
                board[row - 1][col - 1].setContainingValue(' ');
            }
            else if(board[row - 1][col].getContainingValue() == 'W')
            {
                index = indexFinder(red_pieces, player, row - 2, col);
                if(red_pieces[index].getIsKing())
                {
                    red_pieces[index].makeMove(row, col);
                    index = indexFinder(white_pieces, 'W', row - 1, col);
                    modifyPieces(white_pieces, index, 'W');
                    board[row - 2][col].setContainingValue(' ');
                    board[row - 1][col].setContainingValue(' ');
                }
                else if(board[row - 1][col + 1].getContainingValue() == 'W')
                {
                    index = indexFinder(red_pieces, player, row - 2, col + 2);
                    red_pieces[index].makeMove(row, col);
                    index = indexFinder(white_pieces, 'W', row - 1, col + 1);
                    modifyPieces(white_pieces, index, 'W');
                    board[row - 2][col + 2].setContainingValue(' ');
                    board[row - 1][col + 1].setContainingValue(' ');
                }
                else
                {
                    board[row][col].setContainingValue(' ');
                    cout << "Invalid choice!\n";
                }
                
            }

            else if(board[row - 1][col + 1].getContainingValue() == 'W')
            {
                index = indexFinder(red_pieces, player, row - 2, col + 2);
                red_pieces[index].makeMove(row, col);
                index = indexFinder(white_pieces, 'W', row - 1, col + 1);
                modifyPieces(white_pieces, index, 'W');
                board[row - 2][col + 2].setContainingValue(' ');
                board[row - 1][col + 1].setContainingValue(' ');
            }
            else
            {
                board[row][col].setContainingValue(' ');
                cout << "Invalid choice!\n";
            }
            break;

        case 2:
            
            if(board[row - 2][col - 2].getContainingValue() == player && board[row - 2][col].getContainingValue() == player && board[row - 1][col].getContainingValue() == 'W')
            {
                index = indexFinder(red_pieces, player, row - 2, col);
                if(red_pieces[index].getIsKing())
                {
                    red_pieces[index].makeMove(row, col);
                    index = indexFinder(white_pieces, 'W', row - 1, col);
                    modifyPieces(white_pieces, index, 'W');
                    board[row - 2][col].setContainingValue(' ');
                    board[row - 1][col].setContainingValue(' ');
                }
                else if(board[row - 2][col - 2].getContainingValue() == player && board[row - 2][col + 2].getContainingValue() == player && board[row - 1][col + 1].getContainingValue() == 'W')
                {
                    index = indexFinder(red_pieces, player, row - 2, col + 2);
                    red_pieces[index].makeMove(row, col);
                    index = indexFinder(white_pieces, 'W', row - 1, col + 1);
                    modifyPieces(white_pieces, index, 'W');
                    board[row - 2][col + 2].setContainingValue(' ');
                    board[row - 1][col + 1].setContainingValue(' ');
                }
                else
                {
                    board[row][col].setContainingValue(' ');
                    cout << "Invalid choice!\n";
                }
            }
            else if(board[row - 2][col - 2].getContainingValue() == player && board[row - 2][col + 2].getContainingValue() == player && board[row - 1][col + 1].getContainingValue() == 'W')
            {
                index = indexFinder(red_pieces, player, row - 2, col + 2);
                red_pieces[index].makeMove(row, col);
                index = indexFinder(white_pieces, 'W', row - 1, col + 1);
                modifyPieces(white_pieces, index, 'W');
                board[row - 2][col + 2].setContainingValue(' ');
                board[row - 1][col + 1].setContainingValue(' ');
            }
            
            else if(board[row - 2][col].getContainingValue() == player && board[row - 2][col + 2].getContainingValue() == player && board[row - 1][col + 1].getContainingValue() == 'W')
            {
                index = indexFinder(red_pieces, player, row - 2, col + 2);
                red_pieces[index].makeMove(row, col);
                index = indexFinder(white_pieces, 'W', row - 1, col + 1);
                modifyPieces(white_pieces, index, 'W');
                board[row - 2][col + 2].setContainingValue(' ');
                board[row - 1][col + 1].setContainingValue(' ');
            }
            else
            {
                board[row][col].setContainingValue(' ');
                cout << "Invalid choice!\n";
            }

            break;
        default:
            break;
        }
    }
    else
    {
        switch (piece_selector)
        {
        case 1:
            if(board[row + 1][col - 1].getContainingValue() == 'R')
            {
                index = indexFinder(white_pieces, player, row + 2, col - 2);
                white_pieces[index].makeMove(row, col);
                index = indexFinder(red_pieces, 'R', row + 1, col - 1);
                modifyPieces(red_pieces, index, 'R');
                board[row + 2][col - 2].setContainingValue(' ');
                board[row + 1][col - 1].setContainingValue(' ');
            }
            else if(board[row + 1][col].getContainingValue() == 'R')
            {
                index = indexFinder(white_pieces, player, row + 2, col);
                if(white_pieces[index].getIsKing())
                {
                    white_pieces[index].makeMove(row, col);
                    index = indexFinder(red_pieces, 'R', row + 1, col);
                    modifyPieces(red_pieces, index, 'R');
                    board[row + 2][col].setContainingValue(' ');
                    board[row + 1][col].setContainingValue(' ');
                }
                else if(board[row + 1][col + 1].getContainingValue() == 'R')
                {
                    index = indexFinder(white_pieces, player, row + 2, col + 2);
                    white_pieces[index].makeMove(row, col);
                    index = indexFinder(red_pieces, 'R', row + 1, col + 1);
                    modifyPieces(red_pieces, index, 'R');
                    board[row + 2][col + 2].setContainingValue(' ');
                    board[row + 1][col + 1].setContainingValue(' ');
                }
                else
                {
                    board[row][col].setContainingValue(' ');
                    cout << "Invalid choice!\n";
                }
                
            }

            else if(board[row + 1][col + 1].getContainingValue() == 'R')
            {
                index = indexFinder(white_pieces, player, row + 2, col + 2);
                white_pieces[index].makeMove(row, col);
                index = indexFinder(red_pieces, 'R', row + 1, col + 1);
                modifyPieces(red_pieces, index, 'R');
                board[row + 2][col + 2].setContainingValue(' ');
                board[row + 1][col + 1].setContainingValue(' ');
            }
            else
            {
                board[row][col].setContainingValue(' ');
                cout << "Invalid choice!\n";
            }
            break;

        case 2:
            
            if(board[row + 2][col - 2].getContainingValue() == player && board[row + 2][col].getContainingValue() == player && board[row + 1][col].getContainingValue() == 'R')
            {
                index = indexFinder(white_pieces, player, row + 2, col);
                if(white_pieces[index].getIsKing())
                {
                    white_pieces[index].makeMove(row, col);
                    index = indexFinder(red_pieces, 'R', row + 1, col);
                    modifyPieces(red_pieces, index, 'R');
                    board[row + 2][col].setContainingValue(' ');
                    board[row + 1][col].setContainingValue(' ');
                }
                else if(board[row + 2][col - 2].getContainingValue() == player && board[row + 2][col + 2].getContainingValue() == player && board[row + 1][col + 1].getContainingValue() == 'R')
                {
                    index = indexFinder(white_pieces, player, row + 2, col + 2);
                    white_pieces[index].makeMove(row, col);
                    index = indexFinder(red_pieces, 'R', row + 1, col + 1);
                    modifyPieces(red_pieces, index, 'R');
                    board[row + 2][col + 2].setContainingValue(' ');
                    board[row + 1][col + 1].setContainingValue(' ');
                }
                else
                {
                    board[row][col].setContainingValue(' ');
                    cout << "Invalid choice!\n";
                }
            }
            else if(board[row + 2][col - 2].getContainingValue() == player && board[row + 2][col + 2].getContainingValue() == player && board[row + 1][col + 1].getContainingValue() == 'R')
            {
                index = indexFinder(white_pieces, player, row + 2, col + 2);
                white_pieces[index].makeMove(row, col);
                index = indexFinder(red_pieces, 'R', row + 1, col + 1);
                modifyPieces(red_pieces, index, 'R');
                board[row + 2][col + 2].setContainingValue(' ');
                board[row + 1][col + 1].setContainingValue(' ');
            }
            
            else if(board[row + 2][col].getContainingValue() == player && board[row + 2][col + 2].getContainingValue() == player && board[row + 1][col + 1].getContainingValue() == 'R')
            {
                index = indexFinder(white_pieces, player, row + 2, col + 2);
                white_pieces[index].makeMove(row, col);
                index = indexFinder(red_pieces, 'R', row + 1, col + 1);
                modifyPieces(red_pieces, index, 'R');
                board[row + 2][col + 2].setContainingValue(' ');
                board[row + 1][col + 1].setContainingValue(' ');
            }
            else
            {
                board[row][col].setContainingValue(' ');
                cout << "Invalid choice!\n";
            }

            break;
        default:
            break;
        }
    }    
}

void modifyPieces(Piece *&pieces, int ignorePiece, char player)
{
    int numOfPieces;
    if(player == 'R')
        numOfPieces = --numOfReds;
    else
        numOfPieces = --numOfWhites;

    Piece *temp = new Piece[numOfPieces]; 
    
    for(int i = 0, j = 0; j < numOfPieces + 1; i++, j++)
    {
        cout << ignorePiece << endl;
        if(j == ignorePiece)
        {
            i--;
            continue;
        }
        else
            temp[i] = pieces[j];
    }
    pieces = temp;
    delete[] temp;
    Piece::inJump = false;

}