#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<int,ll> m;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    ll ans=0;
    cin>>n>>k;
    for (int i=2;i<=n;++i)
        m[i]=i-1;
    for (int i=n+1;i<=2*n;++i)
        m[i]=2*n-i+1;
    for (int i=2;i<=2*n;++i)
        ans+=(m[i]*m[(i-k)]);
    cout<<ans;
    return 0;
}