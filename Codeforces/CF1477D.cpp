#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 5e5+7;
int l,r,ans[2][mn];
vector<int> edges[mn],v;
bitset<mn> done;

void dfs(int c)
{
    done[c]=1;
    v.push_back(c);
    for (int i : edges[c])
        if (!done[i])
            dfs(i);
}

void solve()
{
    int n,m,x,y;
    cin>>n>>m;
    l=1;r=n;
    for (int i=1;i<=n;++i)
    {
        done[i]=0;
        edges[i].clear();
    }
    while (m--)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for (int i=1;i<=n;++i)
        if (!done[i])
        {
            v.clear();
            dfs(i);
            for (int j : v)
                ans[0][j]=l++;
            for (int j=sz(v)-1;j>=0;--j)
                ans[1][v[j]]=r--;
        }
    for (int i=1;i<=n;++i)
        cout<<ans[0][i]<<" ";
    cout<<"\n";
    for (int i=1;i<=n;++i)
        cout<<ans[1][i]<<" ";
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