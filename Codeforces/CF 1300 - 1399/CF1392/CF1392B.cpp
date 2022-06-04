#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[200000];

void flip(int n)
{
    int mx=-1e9;
    for (int i=0;i<n;++i)
        mx=max(mx,a[i]);
    for (int i=0;i<n;++i)
        a[i]=mx-a[i];
}

void solve()
{
    ll n,k;
    cin>>n>>k;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<min(k,(k&1)+4);++i)
        flip(n);
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