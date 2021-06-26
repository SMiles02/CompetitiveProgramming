#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int mod=998244353;

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    res%=mod;
    if (b % 2)
        return (res * a)%mod;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans=0,x,y;
    cin>>n;
    map<int,int> final;
    map<int,int> initial;
    set<int> s;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        s.insert(a[i]);
        final[a[i]]=i;
    }
    for (int i=n-1;i+1;--i)
        initial[a[i]]=i;
    set<pair<int,int>> start;
    for (int i : s)
        start.insert({initial[i],final[i]});
    while (sz(start))
    {
        x=*(start.begin()).first;
        y=*(start.begin()).second;
        start.erase(start.begin());
        while (sz(start))
        {
            if ((*(start.begin())).first>y)
                break;
            y=max((*(start.begin())).second,y);
            start.erase()
        }
    }
    return 0;
}