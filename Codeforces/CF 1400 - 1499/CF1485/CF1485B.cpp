#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,k,l,r;
    cin>>n>>q>>k;
    int a[n+1];
    ll p[n+1];
    p[0]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        p[i]=0;
    }
    for (int i=2;i<n;++i)
        p[i]=p[i-1]+a[i+1]-a[i-1]-2;
    while (q--)
    {
        cin>>l>>r;
        if (l==r)
            cout<<k-1<<"\n";
        else if (l+1==r)
            cout<<a[r]-2+k-a[l]-1<<"\n";
        else
            cout<<p[r-1]-p[l]+k-a[r-1]-1+a[l+1]-2<<"\n";
    }
    return 0;
}