#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

int n=1000;
long long x[1000000],t[1000000];
ifstream f("fisier_nrdesc");
ofstream g("fisier4.out");

void interclasare(long long x[],long long s,long long d,long long m)
{
    long long i=s,j=m+1,k=0;
    while(i<=m && j<=d)
    {
        k++;
        if(x[i]>=x[j])
        {
            t[k]=x[i];
            i++;
        }
        else
        {
            t[k]=x[j];
            j++;
        }
    }
    while(i<=m)
    {
        k++;
        t[k]=x[i];
        i++;
    }
    while(j<=d)
    {
        k++;
        t[k]=x[j];
        j++;
    }
    for(i = s , j = 1 ; i <= d ; i ++ , j ++)
			x[i] = t[j];
}

void sortare(long long x[],long long s,long long d)
{
    if(s<d)
    {
        long long m=(s+d)/2;
        sortare(x,s,m);
        sortare(x,m+1,d);
        interclasare(x,s,d,m);
    }
}

int main()
{
    srand(0);
    for(long long i=0;i<1000000;i++)
        x[i]=rand();
    sortare(x,1,999999);
    for(long long i=0;i<1000000;i++)
        g<<x[i]<<endl;
    return 0;
}
