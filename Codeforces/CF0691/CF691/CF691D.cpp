#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int ans[1000001];
int p[1000001];
bool done[1000001];
vector<int> edges[1000001];
vector<int> v;
vector<int> w;

void dfs(int cur)
{
    done[cur]=1;
    v.push_back(cur);
    w.push_back(p[cur]);
    for (auto i : edges[cur])
        if (!done[i])
            dfs(i);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,u,y;
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>p[i];
    while (m--)
    {
        cin>>u>>y;
        edges[u].push_back(y);
        edges[y].push_back(u);
    }
    for (int i=1;i<=n;++i)
        if (!done[i])
        {
            v.clear();
            w.clear();
            dfs(i);
            sort(v.begin(), v.end());
            sort(w.rbegin(), w.rend());
            y=sz(v);
            for (int i=0;i<y;++i)
                ans[v[i]]=w[i];
        }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    return 0;
}