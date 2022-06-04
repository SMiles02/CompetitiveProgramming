#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
void solve()
{
    ll n,k;
    cin>>n>>k;
    for (ll i=1;i<=100000;++i)
        if (!(n%i))
            if (n/i<=k)
            {
                cout<<i<<"\n";
                return;
            }
    for (ll i=100000;i>0;--i)
        if (!(n%i))
            if (i<=k)
            {
                cout<<n/i<<"\n";
                return;
            }
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