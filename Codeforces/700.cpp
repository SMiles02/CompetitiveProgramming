#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m,k,ans=0,cur;
    cin>>n>>m>>k;
    int a[n+1];
    k=min(k,m-1);
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=0;i<=k;++i)
    {
        cur=1e9;
        for (int x=i+1,y=n-k+i-m+k+1;y<=n-k+i;++x,++y)
            cur=min(cur,max(a[x],a[y]));
        ans=max(ans,cur);
    }
    cout<<ans<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}