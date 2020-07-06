#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,tA,tB,k,ans=0,l,r,mid;
    cin>>n>>m>>tA>>tB>>k;
    if (k>=n||k>=m)
    {
        cout<<-1;
        return 0;
    }
    int a[n];
    int b[m];
    for (int i=0;i<n;++i) cin>>a[i];
    for (int i=0;i<m;++i) cin>>b[i];
    for (int i=0;i<=k;++i)
    {
        if (a[i]+tA>b[m-1])
        {
            cout<<-1;
            return 0;
        }
        l=0,r=m-1;
        while (l<r)
        {
            mid=l+(r-l)/2;
            if (a[i]+tA>b[mid]) l=mid+1;
            else r=mid;
        }
        if (l+k-i>=m)
        {
            cout<<-1;
            return 0;
        }
        ans=max(ans,b[l+k-i]+tB);
    }
    cout<<ans;
    return 0;
}