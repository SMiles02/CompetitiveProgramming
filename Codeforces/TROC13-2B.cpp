#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,m,r,x;
    cin>>n>>m>>r;
    x=min(n,m);
    cout<<x/(2*r+1)+min(1,x%(2*r+1));
    return 0;
}