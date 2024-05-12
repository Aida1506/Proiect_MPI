#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

int n=1000;
long long x[1000000];
ifstream f("fisier_nrdesc");
ofstream g("fisier2.out");

void selectie(long long x[])
{
    for(long long i=0;i<999999;i++)
    {
       long long k=i;
       for(long long j=i+1;j<=1000000;j++)
            if(x[k]>x[j]) k=j;
       if(k!=i)
       {
           long long aux=x[i];
           x[i]=x[k];
           x[k]=aux;
       }
    }
}

int main()
{
    srand(0);
    for(long long i=0;i<1000000;i++)
        f>>x[i];
    selectie(x);
    for(long long i=0;i<1000000;i++)
        g<<x[i]<<endl;
    return 0;
}
