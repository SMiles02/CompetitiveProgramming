#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,k;
    int a[2];
    a[0]=0;
    a[1]=0;
    cin>>n;
    while (n--)
    {
        cin>>k;
        ++a[k%2];
    }
    if ((a[0]==0&&a[1]%2==0)||(a[1]==0))
    {
        cout<<"NO\n";
    }
    else
    {
        cout<<"YES\n";
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}