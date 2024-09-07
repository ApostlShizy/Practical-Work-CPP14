#include<iostream>

int main()
{
    bool bubble[12][12] = {
        {true,true,true,true,true,true,true,true,true,true,true,true},
        {true,true,true,true,true,true,true,true,true,true,true,true},
        {true,true,true,true,true,true,true,true,true,true,true,true},
        {true,true,true,true,true,true,true,true,true,true,true,true},
        {true,true,true,true,true,true,true,true,true,true,true,true},
        {true,true,true,true,true,true,true,true,true,true,true,true},
        {true,true,true,true,true,true,true,true,true,true,true,true},
        {true,true,true,true,true,true,true,true,true,true,true,true},
        {true,true,true,true,true,true,true,true,true,true,true,true},
        {true,true,true,true,true,true,true,true,true,true,true,true},
        {true,true,true,true,true,true,true,true,true,true,true,true},
        {true,true,true,true,true,true,true,true,true,true,true,true}
    };

    int firstAngle = 0;
    int secondAngle = 0;
    int minY = 0;
    int maxY = 0;
    int maxX = 0;
    int minX = 0;
    int count = 0;

    for(int i = 0;i < 12;++i)
    {
        for(int j = 0; j < 12;++j)
        {
            if(bubble[i][j])
            {
                count++;
            }
        }    
    }    

    while(count != 0)
    {

        std::cout<<"\nTotal bubles: "<<count;
        std::cout<<"\nEnter first angle (0 - 143): ";
        std::cin>>firstAngle;
        std::cout<<"\nEnter second angle (0 - 143): ";
        std::cin>>secondAngle;
        if(firstAngle / 12 > secondAngle / 12)
        {
            maxY = firstAngle / 12;
            minY = secondAngle / 12;
        }
        else
        {
            maxY = secondAngle / 12;
            minY = firstAngle / 12;
        }
        if(firstAngle % 12 > secondAngle % 12)
        {
            maxX = firstAngle % 12;
            minX = secondAngle % 12;
        }
        else
        {
            maxX = secondAngle % 12;
            minX = firstAngle % 12;
        }
        for(int i = minY;i <= maxY;++i)
        {
            for(int j = minX; j <= maxX;++j)
            {
                if(bubble[i][j])
                {
                    bubble[i][j] = false;
                    --count;
                }
            }
        }
    }
    std::cout<<"\nNo bubbles anymore :(";
}