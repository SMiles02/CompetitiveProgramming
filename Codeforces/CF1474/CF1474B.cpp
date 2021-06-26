#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 100000;
bitset<mn> sieve;
vector<int> primes={2};

int smol(int k)
{
    int l=0,r=9591,m;
    while (l^r)
    {
        m=l+(r-l)/2;
        if (primes[m]<k)
            l=m+1;
        else
            r=m;
    }
    return primes[l];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=3;i<mn;i+=2)
        if (!sieve[i])
        {
            primes.push_back(i);
            for (int j=3*i;j<mn;j+=i+i)
                sieve[j]=1;
        }
    int t,d;
    cin>>t;
    while (t--)
    {
        cin>>d;
        cout<<1LL*smol(1+d)*smol(smol(1+d)+d)<<"\n";
    }
    return 0;
}