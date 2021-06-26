#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,l,r,m;
    ll ans=0;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
    {
        cin>>k;
        a[i]-=k;
    }
    sort(a,a+n);
    for (int i=0;i<n;++i)
    {
        if (a[i]+a[n-1]<=0)
            continue;
        l=0;r=n-1;
        while (l<r)
        {
            m=l+((r-l)>>1);
            if (a[i]+a[m]>0)
                r=m;
            else
                l=m+1;
        }
        ans+=n-l;
        if (a[i]>0)
            --ans;
    }
    cout<<(ans>>1);
    return 0;
}