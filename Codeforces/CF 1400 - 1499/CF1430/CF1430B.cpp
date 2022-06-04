#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    ll a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n,greater<int>());
    for (int i=1;i<=k;++i)
        a[0]+=a[i];
    cout<<a[0]<<"\n";
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