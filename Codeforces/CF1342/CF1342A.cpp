#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll min(ll a, ll b)
{
    if (a>b) return b;
    return a;
}

void solve()
{
    ll x,y,a,b;
    cin>>x>>y;
    cin>>a>>b;
    cout<<min(min(x,y)*b+a*abs(x-y),(x+y)*a)<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--) solve();
    return 0;
}