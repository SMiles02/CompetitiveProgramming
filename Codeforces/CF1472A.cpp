#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int f(int x, int y)
{
    if ((x&1)==0)
        return 2*f(x/2,y);
    if ((y&1)==0)
        return 2*f(x,y/2);
    return 1;
}

void solve()
{
    int x,y,n;
    cin>>x>>y>>n;
    if (f(x,y)>=n)
        cout<<"YES\n";
    else
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