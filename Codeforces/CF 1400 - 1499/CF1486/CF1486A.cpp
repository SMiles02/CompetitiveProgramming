#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin>>n;
    ll a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i+1<n;++i)
    {
        if (a[i]<i)
        {
            cout<<"NO\n";
            return;
        }
        a[i+1]+=a[i]-i;
        a[i]-=i;
    }
    if (a[n-1]<n-1)
        cout<<"NO\n";
    else
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