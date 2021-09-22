#include <bits/stdc++.h>
#define ll long long
using namespace std;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,l,r,m;
    cin>>n;
    ll a[n],x,y,s=0;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        s+=a[i];
    }
    sort(a,a+n);
    cin>>q;
    while (q--)
    {
        cin>>x>>y;
        if (a[n-1]<x)
        {
            cout<<max(0LL,x-a[n-1])+max(0LL,y-s+a[n-1])<<"\n";
            continue;
        }
        l=0;r=n-1;
        while (l<r)
        {
            m=l+(r-l)/2;
            if (a[m]<x)
                l=m+1;
            else
                r=m;
        }
        if (l==0)
            cout<<max(0LL,x-a[l])+max(0LL,y-s+a[l])<<"\n";
        else
            cout<<min(max(0LL,x-a[l])+max(0LL,y-s+a[l]),max(0LL,x-a[l-1])+max(0LL,y-s+a[l-1]))<<"\n";
    }
    return 0;
}