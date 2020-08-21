#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll ans;
ll a[3],b[3];

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

void f(int x, int y, int z)
{
    ll k=min(a[x],b[y]);
    a[x]-=k;
    b[y]-=k;
    ans+=z*(k);
}

void solve()
{
    ans=0;
    for (int i=0;i<3;++i)
        cin>>a[i];
    for (int i=0;i<3;++i)
        cin>>b[i];
    f(2,1,2);
    f(2,2,0);
    f(2,0,0);
    f(0,2,0);
    f(0,0,0);
    f(0,1,0);
    f(1,1,0);
    f(1,0,0);
    f(1,2,-2);
    cout<<ans<<"\n";
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