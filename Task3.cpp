#include<iostream>

int main()
{
    int a[4][4];
    int b[4][4];

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            std::cout << "\nEnter a (" << j + 4 * i << "): ";
            std::cin >> a[i][j];
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            std::cout << "\nEnter b (" << j + 4 * i << "): ";
            std::cin >> b[i][j];
            if(a[i][j] != b[i][j])
            {
                std::cout<<"\nMatrix not equal !";
                return 0;
            }
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (i != j)
            {
                a[i][j] = 0;
            }
            if(a[i][j] == 0)
            {
                std::cout<<" ";
            }
            else
            {
                std::cout<<a[i][j]<<" ";
            }
        }
        std::cout << std::endl;
    }    
}