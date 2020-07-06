#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
using namespace std;

vector<int> children[200001];
int parents[200001];
bool done[200001];

void solve()
{
    int n,m,u,v;
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        parents[i]=0;
        children[i].clear();
        done[i]=0;
    }
    for (int i=0;i<m;++i)
    {
        cin>>u>>v;
        children[u].push_back(v);
        ++parents[v];
    }
    priority_queue<pii,vector<pii>,greater<pii>> q;
    for (int i=1;i<=n;++i)
        if (!parents[i])
        {
            q.push({0,i});
            done[i]=1;
        }
    vector<int> ans;
    while (!q.empty())
    {
        u=q.top().first;v=q.top().second;
        q.pop();
        if (u)
        {
            if (sz(children[v]))
            {
                ans.push_back(v);
                for (auto x : children[v])
                {
                    --parents[x];
                    if (parents[x]==0&&!done[x])
                    {
                        q.push({0,x});
                        done[x]=1;
                    }
                }
            }
        }
        else
        {
            for (int x : children[v])
            {
                if (!done[x])
                {
                    q.push({1,x});
                    done[x]=1;
                }
            }
        }
    }
    cout<<sz(ans)<<"\n";
    for (int i : ans)
        cout<<i<<" ";
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