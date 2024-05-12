#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

long long n=1000000;
long long x[1000000];
ofstream g("fisier6.out");

void counting(long long x[],long long m)
{
    long long f[10],y[1000000];
    for(long long i=0;i<=m;i++) f[i]=0;
    for(long long i=0;i<n;i++) f[x[i]]=f[x[i]]+1;
    for(long long i=1;i<=m;i++) f[i]=f[i-1]+f[i];
    for(long long i=n;i>0;i--)
    {
        y[f[x[i]]]=x[i];
        f[x[i]]=f[x[i]]-1;
    }
    for(long long i=1;i<=n;i++)x[i]=y[i];
}

int main()
{
    srand(0);
    for(long long i=0;i<1000000;i++)
        x[i]=rand()%10;
    counting(x,9);
    for(long long i=0;i<1000000;i++)
        g<<x[i]<<endl;
    return 0;
}
