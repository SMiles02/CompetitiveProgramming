#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll max(ll a, ll b)
{
    return (a>b ? a : b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,m=0,k,s=0;
    cin>>n;
    for (ll i=0;i<n;++i)
    {
        cin>>k;
        s+=k;
        m=max(m,k);
    }
    cout<<max(2*m,s);
    return 0;
}