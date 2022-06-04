#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define MOD 1000000007
using namespace std;

ll binpow(ll a, ll b) {
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    res%=MOD;
    if (b % 2)
        return (res*a)%MOD;
    else
        return res%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,k;
    cin>>n;
    k=binpow(3,3*n)-binpow(7,n);
    while (k<0)
    {
        k+=MOD;
    }
    k%=MOD;
    cout<<k;
    return 0;
}