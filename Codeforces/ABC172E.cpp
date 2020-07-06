#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,m,ans=1;
    cin>>n>>m;
    if (n==1)
    {
        cout<<(m*(m-1))%mod;
        return 0;
    }
    
    return 0;
}