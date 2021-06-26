#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k,ans=0;
    cin>>n;
    while (n--)
    {
        cin>>k;
        ans+=k&1;
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