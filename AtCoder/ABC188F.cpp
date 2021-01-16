#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll x,y;
map<ll,ll> m;

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

ll f(ll k)
{
    if (k<=x)
        return x-k;
    if (m[k])
        return m[k];
    if (k&1)
        return m[k]=min(min(f(k/2+1),f(k/2))+2,k-x);
    return m[k]=min(1+f(k/2),k-x);;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>x>>y;
    if (x>=y)
    {
        cout<<x-y;
        return 0;
    }
    cout<<f(y)<<"\n";
    return 0;
}