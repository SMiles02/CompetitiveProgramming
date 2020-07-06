#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll sq(ll a)
{
    return a*a;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    cout<<sq(min(max(2*n,m),max(2*m,n)))<<"\n";
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