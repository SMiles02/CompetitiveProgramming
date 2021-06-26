#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll sum(ll n)
{
    ll k=n;
    k*=(k+1);
    return k/2;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,k,ans=1,x;
    int mod=998244353,last=-1;
    cin>>n>>k;
    cout<<sum(n)-sum(n-k);
    for (int i=0;i<n;++i)
    {
        cin>>x;
        if (x>n-k)
        {
            if (last>-1)
            {
                ans*=(i-last);
                ans%=mod;
            }
            last=i;
        }
    }
    cout<<" "<<ans;
    return 0;
}