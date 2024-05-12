#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

int n=1000;
long long x[1000000];
ifstream f("fisier_nrdesc");
ofstream g("fisier5.out");

 long long pivot(long long x[],long long s,long long d)
{
    long long v=x[d],i=s-1,j=d;
    while(i<j)
    {
        do{
            i++;
        }while(x[i]>=v);
        do{
            j--;
        }while(x[j]<=v);
        if(i<j)
        {
            long long aux=x[i];
            x[i]=x[j];
            x[j]=aux;
        }
    }
    long long aux=x[i];
    x[i]=x[d];
    x[d]=aux;
    return i;
}

void quick(long long x[],long long s,long long d)
{
    if(s<d)
    {
        long long q=pivot(x,s,d);
        quick(x,s,q-1);
        quick(x,q,d);
    }
}

void QuickSort(long long v[], long long st, long long dr)
{
	if(st < dr)
	{
		//pivotul este inițial v[st]
		long long m = (st + dr) / 2;
		long long aux = v[st];
		v[st] = v[m];
		v[m] = aux;
		long long i = st , j = dr, d = 0;
		while(i < j)
		{
			if(v[i] > v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		QuickSort(v, st , i - 1);
		QuickSort(v, i + 1 , dr);
	}
}

int main()
{
    srand(0);
    for(long long i=0;i<1000000;i++)
        f>>x[i];
    QuickSort(x,1,999999);
    for(long long i=0;i<1000000;i++)
        g<<x[i]<<endl;
    return 0;
}
