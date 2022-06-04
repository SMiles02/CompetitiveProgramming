#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    long long s=0,ans=0;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        s+=a[i];
    }
    s*=2;
    if (s%n)
    {
        cout<<"0\n";
        return;
    }
    s/=n;
    map<int,int> m;
    for (int i=0;i<n;++i)
    {
        ans+=m[s-a[i]];
        ++m[a[i]];
    }
    cout<<ans<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}