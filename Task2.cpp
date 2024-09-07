#include<iostream>

bool winner(char board[][3])
{    
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            std::cout << "\n\nWinner player: " << board[i][0];
            return false;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            std::cout << "\n\nWinner player: " << board[i][0];
            return false;
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        std::cout << "\n\nWinner player: " << board[0][0];
        return false;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        std::cout << "\n\nWinner player: " << board[0][2];
        return false;
    }
    return true;
}

void check(char board[][3], char turn)
{
    int x;
    std::cout << "\nEnter column number (0-2): ";
    std::cin >> x;
    while (x < 0 || x > 2)
    {
        std::cout << "\nWrong number try again: ";
        std::cout << "\nEnter column number: ";
        std::cin >> x;
    }
    int y;
    std::cout << "\nEnter line number (0-2): ";
    std::cin >> y;
    while (y < 0 || y > 2)
    {
        std::cout << "\nWrong number try again: ";
        std::cout << "\nEnter line number: ";
        std::cin >> y;
    }
    if (board[x][y] == ' ')
    {
        board[x][y] = turn;
    }
    else
    {
        std::cout << "\nThat slot ocupat try again.";
        check(board, turn);
    }
}

void display(char board[][3])
{
    std::cout <<"\n" << board[0][0] << " | " << board[0][1] << " | " << board[0][2];
    std::cout << "\n----------\n";
    std::cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2];
    std::cout << "\n----------\n";
    std::cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << std::endl;
}

int main()
{
    std::cout << "\nTo make move choice numbers: " << std::endl;
    std::cout << "0-0 | 0-1 | 0-2";
    std::cout << "\n--------------\n";
    std::cout << "1-0 | 1-1 | 1-2";
    std::cout << "\n-------------\n";
    std::cout << "2-0 | 2-1 | 2-2" << std::endl;

    char board[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    char turn = 'X';
    int moves = 9;

    while (moves != 0 && winner(board))
    {
        moves--;
        if (turn == 'X')
        {
            std::cout << "\nThat player X\n";
            check(board, turn);
            turn = 'O';
        }
        else
        {
            std::cout << "\nThat player O\n";
            check(board, turn);
            turn = 'X';
        }
        display(board);        
    }
}