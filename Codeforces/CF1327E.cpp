#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int mod=998244353;

int binpow(int a, int b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    ll powers[n];
    powers[0]=1;
    for (int i=1;i<n;++i)
    {
        powers[i]=powers[i-1]*10;
        powers[i]%=mod;
    }
    for (int i=1;i<n;++i)
    {
        cout<<((((n-i-1)*(powers[n-i-1]*81))%mod)+((18*powers[n-i])%mod))%mod<<" ";
    }
    cout<<10;
    return 0;
}