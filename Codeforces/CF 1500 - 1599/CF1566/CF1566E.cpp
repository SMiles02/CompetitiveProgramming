#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5+1;
int cd[N], cO[N], ans;
vector<int> e[N], v, w;

void dfs(int c, int p)
{
    cd[c]=cO[c]=0;
    for (int i : e[c])
        if (i!=p)
        {
            dfs(i,c);
            if (!cO[i])
                ++cd[c];
        }
    if (c!=1)
    {
        if (cd[c])
        {
            v.push_back(cd[c]);
            ans+=cd[c];
            cO[c]=1;
        }
    }
}

void solve()
{
    int n,x,y;
    cin>>n;
    ans=0;
    v.clear();
    w.clear();
    for (int i=0;i<=n;++i)
        e[i].clear();
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1,0);
    ans+=cd[1];
    while (cd[1]&&!v.empty())
    {
        w.push_back(v.back());
        v.pop_back();
        --ans;
    }
    while (!v.empty()&&!w.empty())
    {
        w.push_back(v.back());
        v.pop_back();
        --ans;
    }
    cout<<ans-max(0,sz(v)-1)<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}