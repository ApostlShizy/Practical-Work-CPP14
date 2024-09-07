#include<iostream>
#include<cmath>

bool battle(bool board[][10])
{
    int x = 0;
    int y = 0;
    std::cout << "\nEnter X and Y: ";
    std::cin >> x >> y;
    if ((x >= 0 && x <= 9) && (y >= 0 && y <= 9) && board[y][x])
    {
        std::cout << "\nYou got him !";
        board[y][x] = false;
        return true;
    }
    else
    {
        std::cout << "\nYou missed !";
        return false;
    }
}

void display(bool board[][10])
{
    std::cout << "    ";
    for (int i = 0; i < 10; ++i)
    {
        std::cout << i << " ";
    }
    std::cout<<"\n\n";
    for (int i = 0; i < 10; ++i)
    {      
        std::cout << i << "   ";       
        for (int j = 0; j < 10; ++j)
        {
           
            if (board[i][j])
            {
                std::cout << "+ ";
            }
            else 
            {
                std::cout << "O ";
            }           
        }
        std::cout << std::endl;
    }
}

bool check_long_ship(bool player_board[][10], int type)
{
    int start_x = 0;
    int start_y = 0;
    int end_y = 0;
    int end_x = 0;    

    std::cout << "\nEnter start point of ship X and Y: ";
    std::cin >> start_x >> start_y;
    std::cout << "Enter end point of ship X and Y: ";
    std::cin >> end_x >> end_y;

    if (start_x == end_x)
    {
        if (abs(start_y - end_y) != type)
        {
            std::cout << "\nIncorrect input try again. (Incorrect ship length)";
            return false;
        }
    }
    else if (start_y == end_y)
    {
        if (abs(start_x - end_x) != type)
        {
            std::cout << "\nIncorrect input try again. (Incorrect ship length)";
            return false;
        }
    }
    else
    {
        std::cout << "\nIncorrect input try again.";
        return false;
    }    

    if (start_y > end_y)
    {
        int temp = 0;
        temp = start_y;
        start_y = end_y;
        end_y = start_y;
    }  
    if (start_x > end_x)
    {
        int temp = 0;
        temp = start_x;
        start_x = end_x;
        end_x = temp;
    }

    if (start_x < 0 || end_x > 9 || start_y < 0 || end_y > 9)
    {
        std::cout << "\nIncorrect input try again.";
        return false;
    }
  
    for (int i = start_y; i <= end_y; ++i)
    {
        for (int j = start_x; j <= end_x; ++j)
        {
            if (player_board[i][j])
            {
                std::cout << "\nThis position is filled try again.";
                return false;
            }            
        }
    }
    for (int i = start_y; i <= end_y; ++i)
    {
        for (int j = start_x; j <= end_x; ++j)
        { 
            player_board[i][j] = true;           
        }
    }
    return true;
}

bool check_small_ship(bool player_board[][10])
{
    int x = 0;
    int y = 0;
    std::cout << "\nTo place small ship input X and Y: ";
    std::cin >> x >> y;
    if ((y < 0 || y > 9) || (x < 0 || x > 9))
    {
        std::cout << "\nIncorrect input try again.";
        return false;
    }
    if (player_board[y][x])
    {
        std::cout << "\nThis position is filled try again.";
        return false;
    }
    player_board[y][x] = true;
    return true;
}

void addShip(bool player_board[][10])
{
    int smallShip = 4;
    int mediumShip = 3;
    int bigShip = 2;
    int largeShip = 1;

    while (smallShip != 0)
    {
        if (check_small_ship(player_board))
        {
            --smallShip;
        }
    }
    while (mediumShip != 0)
    {
        std::cout << "\nShip on 2 points.";
        if (check_long_ship(player_board, 1))
        {
            --mediumShip;
        }
    }
    while (bigShip != 0)
    {
        std::cout << "\nShip on 3 points.";
        if (check_long_ship(player_board, 2))
        {
            --bigShip;
        }
    }
    while (largeShip != 0)
    {
        std::cout << "\nShip on 4 points.";
        if (check_long_ship(player_board, 3))
        {
            --largeShip;
        }
    }
}

int main()
{
    bool player_1_board[10][10] {
    {false,false,false,false,false,false,false,false,false,false,},
    {false,false,false,false,false,false,false,false,false,false,},
    {false,false,false,false,false,false,false,false,false,false,},
    {false,false,false,false,false,false,false,false,false,false,},
    {false,false,false,false,false,false,false,false,false,false,},
    {false,false,false,false,false,false,false,false,false,false,},
    {false,false,false,false,false,false,false,false,false,false,},
    {false,false,false,false,false,false,false,false,false,false,},
    {false,false,false,false,false,false,false,false,false,false,},
    {false,false,false,false,false,false,false,false,false,false,}
    };
    bool player_2_board[10][10] {
    {false,false,false,false,false,false,false,false,false,false,},
    {false,false,false,false,false,false,false,false,false,false,},
    {false,false,false,false,false,false,false,false,false,false,},
    {false,false,false,false,false,false,false,false,false,false,},
    {false,false,false,false,false,false,false,false,false,false,},
    {false,false,false,false,false,false,false,false,false,false,},
    {false,false,false,false,false,false,false,false,false,false,},
    {false,false,false,false,false,false,false,false,false,false,},
    {false,false,false,false,false,false,false,false,false,false,},
    {false,false,false,false,false,false,false,false,false,false,}
    };

    std::cout << "\nPlayer 1 start adding ships !\n";
    addShip(player_1_board);
    std::cout << "\n*************************\n";
    std::cout << "\nPlayer 2 start adding ships !\n";
    addShip(player_2_board);

    int player_1_points = 20; /* Количество точек которые занимают корабли, если они кончатся значит игрок проиграл */ 
    int player_2_points = 20; /* Веду подсчёт чтобы не проверять каждый раз массив на отсудствие кораблей */

    while (player_1_points != 0 && player_2_points != 0)
    {
        std::cout << "\nIts player 1 turn !!!\n";
        if (battle(player_2_board))
        {
            --player_2_points;
        }
        std::cout << "\n\n*************************\nIts player 2 turn !!!\n";
        if (battle(player_1_board))
        {
            --player_1_points;
        }

        std::cout << "\n*************************\nPlayer 1 boart\n";
        display(player_1_board);
        std::cout << "\n*************************\n";
        std::cout << "\n\n\n*************************\nPlayer 2 boart\n";
        display(player_2_board);
        std::cout << "\n\n\n*************************\n";
    }

    if (player_1_points == 0)
    {
        std::cout << "\nPlayer 2 win !";
    }
    else
    {
        std::cout << "\nPlayer 1 win !";
    } 
}