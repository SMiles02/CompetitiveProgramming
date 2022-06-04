#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,x,s=0;
    cin>>n>>x;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        s+=a[i];
    }
    if (s==x)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    s=0;
    for (int i=0;i<n;++i)
    {
        if (s+a[i]==x)
            swap(a[i],a[i+1]);
        s+=a[i];
    }
    for (int i=0;i<n;++i)
        cout<<a[i]<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}