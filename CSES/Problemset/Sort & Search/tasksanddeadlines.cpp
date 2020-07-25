#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    ll cur=0,ans=0;
    cin>>n;
    int p[n];
    for (int i=0;i<n;++i)
    {
        cin>>p[i]>>k;
        ans+=k;
    }
    sort(p,p+n);
    for (int i=0;i<n;++i)
    {
        cur+=p[i];
        ans-=cur;
    }
    cout<<ans;
    return 0;
}