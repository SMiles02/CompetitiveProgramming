#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll binpow(ll a, ll b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
    }
    return res;
}

ll summer(ll n)
{
    return (n*(n+1))/2;
}

ll min(ll a, ll b)
{
    if (a>b)
    {
        return b;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    ll n,m,k,o;
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        if (m==0)
        {
            cout<<"0\n";
        }
        else if (m==1)
        {
            if (n%2)
            {
                cout<<binpow(n/2+1,2)<<"\n";
            }
            else
            {
                cout<<(n/2)*(n/2+1)<<"\n";
            }
        }
        else if (n==m)
        {
            cout<<summer(n)<<"\n";
        }
        else
        {
            o=n-m;
            k=min(o,m+1);
            cout<<summer(n)-((o%k)*summer((o/k)+1) + (k-(o%k))*summer(o/k))<<"\n";
        }
    }
    return 0;
}