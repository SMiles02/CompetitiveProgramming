#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;

void solve()
{
    int n,mn=INF,id;
    cin>>n;
    int a[n+1];
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        if (a[i]<mn)
        {
            mn=a[i];
            id=i;
        }
    }
    cout<<n-1<<"\n";
    for (int i=1;i<=n;++i)
        if (i!=id)
            cout<<id<<" "<<i<<" "<<mn<<" "<<mn+(abs(i-id)&1)<<"\n";
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