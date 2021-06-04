#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t,n,l=1,r=1e15,m;
    cin>>t>>n;
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if ((m*(100+t))/100-m<n)
            l=m;
        else
            r=m-1;
    }
    cout<<l+n;
    return 0;
}