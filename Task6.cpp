#include<iostream>

int main()
{
    int numbers[5][5];
    int num = 0;

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            numbers[i][((4 - j - j) * (i % 2)) + j] = num;
            ++num;
        }        
    }

    for(int i = 0 ; i < 5;++i)
    {
        for(int j = 0;j < 5; ++j)
        {
            std::cout<<numbers[i][j]<<" ";
        }
        std::cout << std::endl;
    }
}
