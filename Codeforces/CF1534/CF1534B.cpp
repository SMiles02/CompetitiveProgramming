#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    long long ans=0;
    cin>>n;
    int a[n+2];
    a[0]=a[n+1]=0;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
        if (a[i-1]<a[i]&&a[i]>a[i+1])
        {
            ans+=a[i]-max(a[i-1],a[i+1]);
            a[i]=max(a[i-1],a[i+1]);
        }
    for (int i=1;i<=n+1;++i)
        ans+=abs(a[i]-a[i-1]);
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