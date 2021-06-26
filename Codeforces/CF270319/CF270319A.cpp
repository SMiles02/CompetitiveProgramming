#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n];
    int b[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for (int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    for (int i=0;i<n;++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    for (int i=0;i<n;++i)
    {
        cout<<b[i]<<" ";
    }
    cout<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}