#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,k,l,r,m;
int a[200000];

ll count(int cur, int goal)
{
    if (cur<=goal)
        return 0;
    if (cur%goal)
        return (cur/goal);
    return (cur/goal)-1;
}

bool check(int x)
{
    ll ans=0;
    for (int i=0;i<n;++i)
        ans+=count(a[i],x);
    if (ans<=k)
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for (int i=0;i<n;++i)
        cin>>a[i];
    l=1;r=1e9;
    while (l<r)
    {
        m=l+(r-l)/2;
        if (check(m))
            r=m;
        else
            l=m+1;
    }
    cout<<l;
    return 0;
}