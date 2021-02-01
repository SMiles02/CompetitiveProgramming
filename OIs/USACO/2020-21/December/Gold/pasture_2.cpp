#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,a[200][2];

int count(int x1, int y1, int x2, int y2)
{
    int r=0;
    for (int i=0;i<n;++i)
        if (x1<=a[i][0]&&a[i][0]<=x2)
            if (y1<=a[i][1]&&a[i][1]<=y2)
                ++r;
    //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<": "<<r<<"\n";
    return r;
}

int cb1(int x, int y, int z)
{
    return count(x,y,x+z,y+z);
}

int cb2(int x, int y, int z)
{
    return count(x-z,y-z,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    ll ans=0;
    for (int i=0;i<n;++i)
        for (int j=0;j<2;++j)
            cin>>a[i][j];
    int x,y,p,q,r,s;
    for (int i=0;i<n;++i)
        for (int j=i+1;j<n;++j)
        {
            p=min(a[i][0],a[j][0]);
            q=min(a[i][1],a[j][1]);
            r=max(a[i][0],a[j][0]);
            s=max(a[i][1],a[j][1]);
            y=max(r-p,s-q);
            x=count(p,q,r,s);
            if (x==count(p,q,p+y,q+y))
                ++ans;
            else if (x==count(r-y,s-y,r,s))
                ++ans;
            else if (x==count(p,s-y,p+y,s))
                ++ans;
            else if (x==count(r-y,q,r,q+y))
                ++ans;
            else
                continue;
            cout<<i<<" "<<j<<"\n";
        }
    cout<<ans;
    return 0;
}