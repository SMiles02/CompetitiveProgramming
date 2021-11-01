#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

void solve()
{
    int n;
    cin>>n;
    bool ok=0;
    ll l=1;
    int a[n+1];
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        if (l<=1e9)
            l=(l*(i+1))/gcd(l,i+1);
        ok|=(a[i]%l==0);
    }
    if (ok)
        cout<<"NO\n";
    else
        cout<<"YES\n";
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