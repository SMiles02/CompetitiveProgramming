#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,y,ans=0,cur;
    cin>>n>>k;
    ll x;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>x;
        y=0;
        while (!(x%10))
        {
            x/=10;
            ++y;
        }
        a[i]=y;
    }
    for (int i=0;i+k-1<n;++i)
    {
        cur=0;
        for (int j=i;j<i+k;++j)
        {
            cur+=a[j];
        }
        ans=max(ans,cur);
    }
    cout<<ans;
    return 0;
}