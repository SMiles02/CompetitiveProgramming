#include <bits/stdc++.h>
using namespace std;

int a[301];

void solve()
{
    int n,d,x;
    cin>>n>>d;
    if (d>2LL*(n/2)*(n/2))
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    if (n&1)
    {
        a[1]=n;
        for (int i=1;i<=(n+1)/2;++i)
            a[i+n/2]=i;
        for (int i=(n+1)/2+1;i<n;++i)
            a[i-n/2]=i;
    }
    else
    {
        for (int i=1;i<=n/2;++i)
            a[i+n/2]=i;
        for (int i=n/2+1;i<=n;++i)
            a[i-n/2]=i;
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            cout<<i<<" "<<j<<" "<<a[i]<<" "<<a[j]<<"\n";
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