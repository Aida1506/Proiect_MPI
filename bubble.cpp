#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

int n=1000;
long long x[100000];
ofstream g("fisier3.out");

void bubble(long long x[])
{
    for(long long i=100000;i>1;i--)
    {
       for(long long j=0;j<=i;j++)
        if(x[j]<x[j-1])
       {
           long long aux=x[j];
           x[j]=x[j+1];
           x[j+1]=x[j];
       }
    }
}

int main()
{
    srand(0);
    for(long long i=0;i<100000;i++)
        x[i]=rand();
    bubble(x);
    for(long long i=0;i<100000;i++)
        g<<x[i]<<endl;
    return 0;
}
