#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll MOD=1000000007;

ll binpow(ll a, ll b) {
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    if (b % 2)
        return ((res * res)%MOD * a)%MOD;
    else
        return (res * res)%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin>>n;
    cout<<((binpow(binpow(26,n/2),MOD-2)))%MOD;
    return 0;
}