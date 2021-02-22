#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b, ll m)
{
    ll res = 1;
    while (b > 0)
    {
        a%=m;
        if (b & 1)
            res = (res * a)%m;
        a = (a * a)%m;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    cout<<binpow(a,binpow(b,c,2520),10);
    return 0;
}