#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    ll k,s=0;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        s+=k-i;
    }
    k=s/n;
    s%=n;
    for (int i=0;i<n;++i)
    {
        cout<<k+min(1,s)+i<<" ";
        s=max(0,--s);
    }
    return 0;
}