#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int f(int x)
{
    int l=0,r=40,m;
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if ((m*(m+1))/2<=x)
            l=m;
        else
            r=m-1;
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin>>n;
    int ans=0,cur=0;
    while (n%2==0)
    {
        n/=2;
        ++cur;
    }
    ans+=f(cur);
    for (ll i=3;i*i<=n;i+=2)
    {
        if (n%i==0)
        {
            cur=0;
            while (n%i==0)
            {
                n/=i;
                ++cur;
            }
            ans+=f(cur);
        }
    }
    if (n>1)
        cout<<ans+1;
    else
        cout<<ans;
    return 0;
}