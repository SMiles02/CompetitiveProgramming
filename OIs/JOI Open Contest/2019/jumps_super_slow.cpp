#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,l,r,ans;
    cin>>n;
    int a[n+1];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    cin>>q;
    while (q--)
    {
        cin>>l>>r;
        ans=0;
        for (int i=l;i<=r;++i)
            for (int j=i+1;j<=r;++j)
                for (int k=j*2-i;k<=r;++k)
                    ans=max(ans,a[i]+a[j]+a[k]);
        cout<<ans<<"\n";
    }
    return 0;
}