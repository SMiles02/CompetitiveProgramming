#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll binpow(ll a, ll b)
{
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    ll x,twoToThirtyTwo=binpow(2,32),fish=0;
    cin>>n>>m;
    int ans[n];
    for (int i=0;i<n;++i)
    {
        cin>>x;
        ans[i]=(x*244002641)%twoToThirtyTwo;
    }
    sort(ans,ans+n);
    for (int i=0;i<m;++i)
    {
        fish+=ans[n-1-i];
    }
    cout<<fish;
    return 0;
}