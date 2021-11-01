#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n],b[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    for (int i=0;i<n;++i)
        if (i-k<0&&i+k>=n&&a[i]!=b[i])
        {
            cout<<"NO\n";
            return;
        }
    cout<<"YES\n";
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