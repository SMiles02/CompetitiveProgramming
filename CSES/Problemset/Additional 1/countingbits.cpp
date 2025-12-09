#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll binpow(ll a, ll b) {
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
        return res * a;
    return res;
}

ll rec(ll k)
{
    if (k==0)
        return 0;
    if (k==1)
        return 1;
    ll x=1;
    for (ll i=0;1;++i)
    {
        if (2*x>k)
            return i*binpow(2,i-1)+1+k-x+rec(k-x);
        x*=2;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin>>n;
    cout<<rec(n);
    return 0;
}