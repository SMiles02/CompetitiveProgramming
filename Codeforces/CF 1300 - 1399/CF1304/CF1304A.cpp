#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    ll x,y,a,b,l=1,r=1000000000,m;
    cin>>x>>y>>a>>b;
    while (l<r)
    {
        m=l+(r-l)/2;
        if (x+a*m==y-b*m)
        {
            cout<<m<<"\n";return;
        }
        if (x+a*m<y-b*m)
        {
            l=m+1;
        }
        else
        {
            r=m-1;
        }
    }
    if (x+a*l==y-b*l)
    {
        cout<<l<<"\n";return;
    }
    cout<<"-1\n";return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}