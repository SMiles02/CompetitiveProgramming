#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll small(ll n)
{
    for (ll i=2;i*i<=n;++i)
        if (n%i==0)
            return i;
    return n;
}

void solve()
{
    ll n,k;
    cin>>n>>k;
    cout<<n+small(n)+2*(k-1)<<"\n";
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