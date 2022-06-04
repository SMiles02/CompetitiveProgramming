#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k=0;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        k+=a[i];
    }
    if (k==0)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    if (k>0)
        sort(a,a+n,greater<int>());
    else
        sort(a,a+n);
    for (int i=0;i<n;++i)
        cout<<a[i]<<" ";
    cout<<"\n";
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