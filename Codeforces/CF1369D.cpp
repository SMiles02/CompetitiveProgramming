#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

int mod=1e9+7;

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
        return res * a;
    return res;
}

ll pos(ll x)
{
    if (x<0)
        x+=mod;
    return x;
}

ll nodes[2000001][3];
ll ans[2000001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    nodes[1][0]=0;
    for (int i=2;i<2000001;++i)
    {
        nodes[i][2]=nodes[i-1][2]+nodes[i-1][1];
        nodes[i][1]=nodes[i-1][0];
        nodes[i][0]=nodes[i-1][0]+2*nodes[i-1][1];
        nodes[i][2]%=mod;
        nodes[i][0]%=mod;
        if (n&1)
        {
            ans[(i+1)/2]=ans[i/2]+pos(nodes[i][2]-nodes[i-2][2])
            
        }
    }
    int n;
    cin>>n;
    return 0;
}