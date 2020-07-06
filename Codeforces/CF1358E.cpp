#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,x;
ll prefix[250001];
bool sieve[500001];

bool check(int k)
{
    for (int i=1;i<=x+1;++i)
    {
        if ()
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    x=n/2+n%2;
    for (int i=1;i<=x;++i)
    {
        cin>>prefix[i];
        prefix[i]+=prefix[i-1];
    }
    for (ll i=3;i<500000;++i)
    {
        if (!sieve[i])
        {
            if (check(i))
            {
                cout<<i;
                return 0;
            }
            for (ll j=i*i;)
        }
    }
    return 0;
}