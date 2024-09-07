#include<iostream>

void multiply_matrix(float a[][4], float b[],float c[])
{
    
    for(int i = 0;i < 4;++i)
    {   
        float sum = 0.f;
        for(int j = 0;j<4;++j)
        {
            std::cout<<a[i][j]<<" * "<< b[j]<<"     ";
            sum += a[i][j] * b[j];
        }
        std::cout<<std::endl;
        c[i] = sum;
    }

}

int main()
{
    float a[4][4];
    float b[4];
    float c[4];    

    for(int i = 0;i < 4;++i)
    {
        for(int j = 0;j<4;++j)
        {
            std::cout<<"\nEnter a: ";
            std::cin>>a[i][j];            
        }        
    }

    for(int i = 0;i < 4;++i)
    {
        std::cout<<"\nEnter b: ";
        std::cin>>b[i];
    }    

    std::cout<<"\n\n";

    multiply_matrix(a,b,c);
    
    std::cout<<std::endl;

    for(int i = 0;i<4;++i)
    {
        std::cout<< c[i] <<" ";
    }
}