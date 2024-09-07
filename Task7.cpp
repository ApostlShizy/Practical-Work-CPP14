#include<iostream>

int main()
{
    bool block[5][5][10] = {
        {{false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false}},
        {{false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false}},
        {{false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false}},
        {{false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false}},
        {{false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false,false,false}}        
    };

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            int height = -1;
            while (height < 0 || height > 9)
            {
                std::cout << "\nEnter height (0-9) Y " << i <<" X "<< j << " : ";
                std::cin >> height;
            }
            for(int k = 0;k <= height; ++k)
            {
                block[i][j][k] = true;
            }            
        }
    }

    int slice = -1;
    while (slice < 0 || slice > 9)
    {
        std::cout << "\nEnter slice (0-9): ";
        std::cin >> slice;
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (block[i][j][slice])
            {
                    std::cout << "1 ";
            }
            else
            {
                std::cout << "0 ";
            }       
        }
        std::cout << std::endl;
    }
}