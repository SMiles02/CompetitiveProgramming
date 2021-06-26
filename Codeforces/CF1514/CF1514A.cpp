#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
    {
        k=sqrt(a[i]);
        if (k*k!=a[i])
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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