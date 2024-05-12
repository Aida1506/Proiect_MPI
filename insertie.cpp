#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

int n=1000;
long long x[1000000];
ifstream f("fisier_nrdesc");
ofstream g("fisier1.out");

void insertie(long long x[])
{
    for(long long i=2;i<1000000;i++)
    {
        long long aux=x[i];
        long long j=i-1;
        while(j>=1 && aux<x[j])
        {
            x[j+1]=x[j];
            j--;
        }
        x[j+1]=aux;
    }
}

int main()
{
    srand(0);
    for(long long i=0;i<1000000;i++)
        f>>x[i];
    insertie(x);
    for(long long i=0;i<1000000;i++)
        g<<x[i]<<endl;
    return 0;
}
