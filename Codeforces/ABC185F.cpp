#include <bits/stdc++.h>
using namespace std;

const int mn=3e5+69;
int bit[mn];

void update(int i, int d)
{
    while (i<mn)
    {
        bit[i]^=d;
        i+=(i&-i);
    }
}

int pre(int i)
{
    int x=0;
    while (i)
    {
        x^=bit[i];
        i-=(i&-i);
    }
    return x;
}

int query(int l, int r)
{
    return pre(r)^pre(l-1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,t,x,y;
    cin>>n>>q;
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        update(i,x);
    }
    while (q--)
    {
        cin>>t>>x>>y;
        if (t==1)
            update(x,y);
        else
            cout<<query(x,y)<<"\n";
    }
    return 0;
}