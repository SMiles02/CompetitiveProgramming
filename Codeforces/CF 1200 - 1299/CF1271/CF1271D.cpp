#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(ll a, ll b) {
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,k;
    cin>>n;
    if (k==1)
    {
        cout<<n;
        return 0;
    }
    if (k==n)
    {
        cout<<1;
        return 0;
    }
    if (k==n-1)
    {
        cout<<2;
        return 0;
    }
    if (n>=binpow(2,59))
    {
        if (n>=binpow(2,59)+binpow(2,58))
        {
            
        }
    }
    for (int i=1;i<60;++i)
    {

    }
    return 0;
}