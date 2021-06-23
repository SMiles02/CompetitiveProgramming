#include <bits/stdc++.h>
#define ll long long
using namespace std;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,l=0,r;
    cin>>n;
    ll ans=0,c=0,x;
    array<ll,2> a[n];
    for (int i=0;i<n;++i)
        cin>>a[i][1]>>a[i][0];
    sort(a,a+n);
    r=n-1;
    while (l<=r)
    {
        x=min(a[r][1],max(a[l][0]-c,0LL));
        a[r][1]-=x;
        c+=x;
        ans+=x*2;
        if (a[l][0]<=c)
        {
            c+=a[l][1];
            ans+=a[l++][1];
        }
        else
            --r;
    }
    cout<<ans;
    return 0;
}