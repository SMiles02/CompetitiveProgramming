#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,k;

int checker(ll v)
{
    ll ans=0;
    double cur = v;
    while (!(cur<1))
    {
        ans+=cur;
        cur/=k;
    }
    return (n<=ans);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    ll l=1,r=10000000000,mid;
    while (l!=r)
    {
        mid=l+(r-l)/2;
        if (checker(mid))
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<l;
    return 0;
}