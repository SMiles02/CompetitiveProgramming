#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n];
    vector<int> v(1e5+1,0);
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        if (i&1)
            ++v[a[i]];
        else
            --v[a[i]];
    }
    sort(a,a+n);
    for (int i=0;i<n;++i)
    {
        if (i&1)
            --v[a[i]];
        else
            ++v[a[i]];
    }
    for (int i=0;i<=1e5;++i)
        if (v[i]>0)
        {
            cout<<"NO\n";
            return;
        }
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