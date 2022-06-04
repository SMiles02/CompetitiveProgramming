#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define MOD 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,m;
    cin>>n>>m;
    ll f[100001];
    f[1]=1;f[2]=2;
    for (int i=3;i<=100000;++i)
    {
        f[i]=(f[i-1]+f[i-2])%MOD;
    }
    cout<<(2*(f[n]+f[m]-1))%MOD;
    return 0;
}