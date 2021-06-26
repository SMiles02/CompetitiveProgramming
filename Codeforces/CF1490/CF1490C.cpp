#include <bits/stdc++.h>
using namespace std;

set<ll> cubes;

void solve()
{
    ll n;
    cin>>n;
    for (ll i : cubes)
        if (cubes.find(n-i)!=cubes.end())
        {
            cout<<"YES\n";
            return;
        }
    cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=1;i<10001;++i)
        cubes.insert(1LL*i*i*i);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}