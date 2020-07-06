#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    ll ans=0,k=1;
    cin>>n>>m;
    ll a[n+1];
    ll factorials[n+1];
    for (int i=1;i<=n;++i)
    {
        k*=i;
        k%=m;
        factorials[i]=k;
        a[i]=(k*i)%m;
        //cout<<factorials[i]<<" "<<a[i]<<"\n";
    }   
    for (int i=n;i;--i)
    {
        ans+=(a[i]*factorials[n-i+1])%m;
    }
    cout<<ans%m;
    return 0;
}