#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int x,y,z,k,t;
set<int> a;
set<int> b;
set<int> c;

int solve(int d, int e)
{
    int ans=0;
    set<int>::iterator it=b.lower_bound(d+1);
    for (int i=d+1;i<=e;++i)
    {
        if (it==b.end())
            ++ans;
        else if (*it==i)
            ++it;
        else
            ++ans;
    }
    it=c.lower_bound(e+1);
    for (int i=e+1;i<=t;++i)
    {
        if (it==c.end())
            ++ans;
        else if (*it==i)
            ++it;
        else
            ++ans;
    }
    return ans;
}

int check(int d)
{
    int ans=0,l,r,m;
    set<int>::iterator it=a.begin();
    for (int i=1;i<=d;++i)
    {
        if (it==a.end())
            ++ans;
        else if (*it==i)
            ++it;
        else
            ++ans;
    }
    if (d==t)
        return ans;
    if (solve(d,d)<solve(d,d+1))
        return ans+solve(d,d);
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if (solve(d,m-1)>=solve(d,m))
            l=m;
        else
            r=m-1;
    }
    return ans+solve(d,l);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>x>>y>>z;
    t=x+y+z;
    for (int i=0;i<x;++i)
    {
        cin>>k;
        a.insert(k);
    }
    for (int i=0;i<y;++i)
    {
        cin>>k;
        b.insert(k);
    }
    for (int i=0;i<z;++i)
    {
        cin>>k;
        c.insert(k);
    }
    for (int i=0;i<=t;++i)
        cout<<i<<": "<<check(i)<<"\n";
    if (check(0)<check(1))
    {
        cout<<check(0);
        return 0;
    }
    int l=1,r=t,m;
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if (check(m-1)>=check(m))
            l=m;
        else
            r=m-1;
    }
    cout<<check(l);
    return 0;
}