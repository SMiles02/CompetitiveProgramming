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

ll ans(ll a, ll b, int x, int y, int n)
{
    if (a-x>n)
    {
        a-=n;
        n=0;
    }
    else
    {
        n-=(a-x);
        a=x;
    }
    b-=n;
    if (b<y)
        b=y;
    return a*b;
}

void solve()
{
    int a,b,x,y,n;
    cin>>a>>b>>x>>y>>n;
    cout<<min(ans(b,a,y,x,n),ans(a,b,x,y,n));
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}