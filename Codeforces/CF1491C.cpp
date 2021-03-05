#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n],inc[n],out[n];
    for (int i=0;i<n;++i)
    {
        inc[i]=out[i]=0;
        cin>>a[i];
    }
    ll ans=0;
    for (int i=0;i<n;++i)
    {
        for (int j=i+2;j<n&&j<=a[i]+i;++j)
        {
            ++out[i];
            ++inc[j];
        }
        ans+=max(a[i]-1-inc[i],0);
        inc[i+1]+=max(0,inc[i]-a[i]+1);
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