#include <iostream>
using namespace std;

class Piece
{
    char player;
    int x_coordinate, y_coordinate;
    bool isKing;

    void init_possible_coordinates(int arr[][2], int rows, int cols = 2)
    {
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                arr[i][j] = -1;
    }

    public:
        Piece(char player, int x_coordinate, int y_coordinate, bool isKing = false)
        {
            this -> player = player;
            this -> x_coordinate = x_coordinate;
            this -> y_coordinate = y_coordinate;
            this -> isKing = isKing;
        }

        void getVals()
        {
            cout << "player: " << player << endl;
            cout << "x_coordinate: " << x_coordinate << endl;
            cout << "y_coordinate: " << y_coordinate << endl;
            cout << "isKing: " << isKing << endl;
        }

        int posibleMoves(char board[8][8])
        {   
            int forward_diagonal_right[] = {y_coordinate + 1, x_coordinate + 1};
            int forward_diagonal_left[] = {y_coordinate + 1, x_coordinate - 1};
            if(!isKing)
            {   
                int possible_coordinates[2][2];
                if(board[forward_diagonal_right[0]][forward_diagonal_right[1]] == ' ')
                {
                    possible_coordinates[0][0] = forward_diagonal_right[0];
                    possible_coordinates[0][1] = forward_diagonal_right[1];
                }

                else if(board[forward_diagonal_right[0]][forward_diagonal_right[1]] != player)
                {
                    forward_diagonal_right[0]++;
                    forward_diagonal_right[1]++;
                    if(board[forward_diagonal_right[0]][forward_diagonal_right[1]] == ' ')
                    {
                        possible_coordinates[0][0] = forward_diagonal_right[0];
                        possible_coordinates[0][1] = forward_diagonal_right[1];
                    }
                }

                if(board[forward_diagonal_left[0]][forward_diagonal_left[1]] == ' ')
                {
                    possible_coordinates[1][0] = forward_diagonal_left[0];
                    possible_coordinates[1][1] = forward_diagonal_left[1];
                }

                else if(board[forward_diagonal_left[0]][forward_diagonal_left[1]] != player)
                {
                    forward_diagonal_left[0]++;
                    forward_diagonal_left[1]--;
                    if(board[forward_diagonal_left[0]][forward_diagonal_left[1]] == ' ')
                    {
                        possible_coordinates[1][0] = forward_diagonal_left[0];
                        possible_coordinates[1][1] = forward_diagonal_left[1];
                    }
                }
            }

            else
            {
                int possible_coordinates[4][2] = {{x_coordinate + 1, y_coordinate + 1},
                 {x_coordinate - 1, y_coordinate + 1}, {x_coordinate, y_coordinate + 1}, {x_coordinate, y_coordinate - 1}};
            }
        }

};

int main()
{
    return 0;
}
