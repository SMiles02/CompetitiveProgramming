#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f(ll p, ll a)
{
    return ((p+a-1)/a)*a-p;
}

void solve()
{
    ll p,a,b,c;
    cin>>p>>a>>b>>c;
    cout<<min({f(p,a),f(p,b),f(p,c)})<<"\n";
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