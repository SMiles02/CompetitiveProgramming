#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k,mx=0,val=0,cur=0,extra=0,dn=0;
    cin>>n>>k;
    int a[n];
    vector<int> f(n+1), g(n+1), p(n+1), ans(n+1);
    vector<vector<int>> v(n+1);
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        v[a[i]].push_back(i);
        ++f[a[i]];
    }
    for (int i=1;i<=n;++i)
        if (f[i])
            ++g[f[i]];
    for (int i=1;i<=n;++i)
        p[i]=p[i-1]+g[i]*i;
    val = k;
    extra=p[k-1]/k;
    for (int i=1;i<=n;++i)
    {
        if (f[i]>=val)
            for (int j=0;j<val;++j)
                ans[v[i][j]]=j+1;
        else
            for (int j=0;j<(int)(v[i]).size&&dn<extra;++j)
            {
                ans[v[i][j]]=++cur;
                if (cur==val)
                {
                    cur=0;
                    ++dn;
                }
            }
    }
    for (int i=0;i<n;++i)
        cout<<ans[i]<<" ";
    cout<<"\n";
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