#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,mod=1e9+7;
    cin>>n;
    ll cur=0,ans=0,k;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        ans+=(k*cur);
        cur+=k;
        cur%=mod;
        ans%=mod;
    }
    cout<<ans;
    return 0;
}