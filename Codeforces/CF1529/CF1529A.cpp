#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k=0;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    for (int i=1;i<n;++i)
        k+=(a[i]!=a[0]);
    cout<<k<<"\n";
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