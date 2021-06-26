#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    ll ans=0;
    int n;
    cin>>n;
    for (ll i=1;i<=n;i+=2)
        ans+=(i/2)*((i*i)-((i-2)*(i-2)));
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