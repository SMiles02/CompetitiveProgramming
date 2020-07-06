#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll powers[63];

ll rec(ll n)
{
    if (n==1)
        return 1;
    for (int i=0;i<63;++i)
        if (powers[i]==n)
            return rec(n/2)*2+1;
    for (int i=0;i<63;++i)
        if (powers[i]>n)
            return rec(powers[i-1])+rec(n-powers[i-1]);
    return 1;
}

void solve()
{
    ll n;
    cin>>n;
    cout<<rec(n)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    powers[0]=1;
    for (int i=1;i<63;++i)
        powers[i]=powers[i-1]*2;
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}