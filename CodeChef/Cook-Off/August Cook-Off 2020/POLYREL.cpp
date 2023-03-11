#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll ans(ll n)
{
    if (n<3)
        return 0;
    return n+ans(n/2);
}

void solve()
{
    ll n,x,y;
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>x>>y;
    cout<<ans(n)<<"\n";
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