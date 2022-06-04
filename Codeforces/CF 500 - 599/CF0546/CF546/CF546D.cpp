#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int g;
int sieve[5000001];
int factors[5000001];
int prefixSum[5000001];

void sieveBuilder()
{
    for (int i=2;i<5000001;i+=2)
    {
        sieve[i]=2;
    }
    for (int i=3;i<5000001;i+=2)
    {
        sieve[i]=1;
    }
    for (int i=3;i<5000001;i+=2)
    {
        if (sieve[i]==1)
        {
            for (int j=3;i*j<5000001;j+=2)
            {
                sieve[i*j]=i;
            }
        }
    }
}

void factorsBuilder()
{
    factors[1]=0;
    for (int i=2;i<5000001;++i)
    {
        factors[i]=factors[i/sieve[i]]+1;
    }
}

void sumBuilder()
{
    prefixSum[1]=0;
    for (int i=2;i<5000001;++i)
    {
        prefixSum[i]=prefixSum[i-1]+factors[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,a,b;
    sieveBuilder();
    factorsBuilder();
    sumBuilder();
    cin>>t;
    while (t--)
    {
        cin>>a>>b;
        cout<<prefixSum[a]-prefixSum[b]<<"\n";
    }
    return 0;
}