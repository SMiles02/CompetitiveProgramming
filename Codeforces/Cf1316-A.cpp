#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,m,above=0;
    cin>>n>>m;
    int a[n];
    cin>>a[0];
    for (int i=1;i<n;++i)
    {
        cin>>a[i];
        above+=a[i];
    }
    cout<<min(above+a[0],m)<<"\n";
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