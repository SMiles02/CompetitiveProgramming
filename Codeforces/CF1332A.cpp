#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int a,b,c,d;
    int x,y,x1,y1,x2,y2,g,h;
    cin>>a>>b>>c>>d;
    cin>>x>>y>>x1>>y1>>x2>>y2;
    g=min(a,b);
    h=min(c,d);
    if (x1<x2)
    {
        a-=g;
        b-=g;
    }
    else if (a||b)
    {
        cout<<"No\n";
        return;
    }
    if (y1!=y2)
    {
        c-=h;
        d-=h;
    }
    else if (c||d)
    {
        cout<<"No\n";
        return;
    }
    if (a)
    {
        if (x-a<x1)
        {
            cout<<"No\n";
            return;
        }
    }
    if (b)
    {
        if (x2<x+b)
        {
            cout<<"No\n";
            return;
        }
    }
    if (c)
    {
        if (y-c<y1)
        {
            cout<<"No\n";
            return;
        }
    }
    if (d)
    {
        if (y2<y+d)
        {
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}