#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll max(ll a, ll b)
{
    if (a>b)
    {
        return a;
    }
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll ans=0,n,k,x;
    cin>>n>>k;
    x=sqrt(n);
    if (k>1000000)
    {
        cout<<-1;
        return 0;
    }
    if (k==1)
    {
        cout<<n;
        return 0;
    }
    if ((k*(k+1))/2<=n)
    {
        ans=1;
    }
    else
    {
        cout<<-1;
        return 0;
    }
    for (int i=2;i<=x;++i)
    {
        if (n%i==0)
        {
            if (((k*(k+1))/2)*i<=n&&((k*(k+1))/2)*i>0)
            {
                ans=max(ans,i);
            }
            if (((k*(k+1))/2)*(n/i)<=n&&((k*(k+1))/2)*(n/i)>0)
            {
                ans=max(ans,n/i);
            }
        }
    }
    if (ans==0)
    {
        cout<<-1;
        return 0;
    }
    for (int i=1;i<k;++i)
    {
        cout<<ans*i<<" ";
    }
    cout<<n-(ans*((k*(k-1))/2));
    return 0;
}