#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    ll a,b,c;
    cin>>a>>b;
    c=abs(a-b);
    for (ll x=0;1;++x)
    {
        if (((x*x+x)/2)>=c&&((x*x+x)/2)%2==c%2)
        {
            cout<<x<<"\n";
            return;
        }
    }
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