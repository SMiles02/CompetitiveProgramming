#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

void solve()
{
    ll n,k,l1,r1,l2,r2;
    cin>>n>>k;
    cin>>l1>>r1;
    cin>>l2>>r2;
    if ((max(r2,r1)-min(l1,l2))*n<k)
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