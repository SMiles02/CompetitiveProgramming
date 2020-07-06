#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll max(ll a, ll b)
{
    if (a>b)
    {
        return a;
    }
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,maxi=-1000000000,cur=0,k;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        cur=max(cur,0)+k;
        maxi=max(maxi,cur);
    }
    cout<<maxi;
    return 0;
}