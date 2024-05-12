#include<iostream>
#include<cstdlib>
#include<fstream>
#include<math.h>
using namespace std;

int n=1000;
long long x[1000000];
ofstream g("fisier7.out");

void counting(long long x[],long long m,long long c)
{
    long long f[10],y[1000000];
    for(long long i=0;i<=m;i++) f[i]=0;
    for(long long i=0;i<=n;i++)
    {
        int j=(x[i]/(int)pow(10,c))%10;
        f[j]=f[j]+1;
    }
    for(long long i=1;i<=m;i++) f[i]=f[i-1]+f[i];
    for(long long i=n;i>=1;i--)
    {
        long long j=(x[i]/(int)pow(10,c))%10;
        y[f[j]]=x[i];
        f[j]=f[j]-1;
    }
    for(long long i=1;i<=n;i++) x[i]=y[i];
}

void radix(long long x[],long long k)
{
    for(long long i=0;i<=k-1;i++) counting(x,9,i);
}

int main()
{
    srand(0);
    for(long long i=0;i<1000000;i++)
        x[i]=rand()%10000;
    radix(x,4);
    for(long long i=0;i<1000000;i++)
        g<<x[i]<<endl;
    return 0;
}
