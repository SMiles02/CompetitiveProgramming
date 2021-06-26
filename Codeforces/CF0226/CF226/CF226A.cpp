#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll n,m;

int binpow(int a, int b) {
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    res%=m;
    if (b % 2)
        return (res * a)%m;
    else
        return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    n=binpow(3,n);
    if (n)
    {
        cout<<n-1;
    }
    else
    {
        cout<<m-1;
    }
    return 0;
}