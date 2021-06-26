#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int maxn = 3e5+7, INF = 1e9;
int n,k,cur,ans[maxn];
vector<int> v[maxn];

void solve()
{
    cin>>n;
    for (int i=0;i<=n;++i)
        ans[i]=INF;
    for (int i=1;i<=n;++i)
    {
        v[i].clear();
        v[i].push_back(-1);
    }
    for (int i=0;i<n;++i)
    {
        cin>>k;
        v[k].push_back(i);
    }
    for (int i=n;i;--i)
    {
        v[i].push_back(n);
        cur=0;
        if (sz(v[i])==2)
            continue;
        for (int j=1;j<sz(v[i]);++j)
            cur=max(cur,v[i][j]-v[i][j-1]);
        ans[cur]=min(ans[cur],i);
    }
    for (int i=1;i<=n;++i)
    {
        ans[i]=min(ans[i],ans[i-1]);
        if (ans[i]==INF)
            cout<<"-1 ";
        else
            cout<<ans[i]<<" ";
    }
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