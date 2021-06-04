#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n,ans=0;
    cin>>n;
    if (n%2050)
    {
        cout<<"-1\n";
        return;
    }
    n/=2050;
    while (n)
    {
        ans+=n%10;
        n/=10;
    }
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