#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k=0;
    cin>>n;
    int a[n],maxi[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=n-1;i+1;--i)
    {
        k=max(max(0,k-1),a[i]+1);
        maxi[i]=k;
    }
    for (int i=1;i<n;++i)
        maxi[i]=max(maxi[i],maxi[i-1]);
    ll ans=0;
    for (int i=0;i<n;++i)
        ans+=maxi[i]-a[i]-1;
    cout<<ans;
    return 0;
}