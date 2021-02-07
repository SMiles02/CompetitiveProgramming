#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int maxn = 1e5 + 7;
int ans[maxn];
vector<int> e1[maxn], e2[maxn];
bitset<maxn> done;
stack<int> s;

void dfs1(int c) //first dfs with regular edges
{
    done[c]=1;
    for (int i : e1[c])
        if (!done[i])
            dfs1(i);
    s.push(c);
}

void dfs2(int c, int k) //second dfs with reversed edges
{
    done[c]=1;
    ans[c]=k; //vertice c is in SCC k
    for (int i : e2[c])
        if (!done[i])
            dfs2(i,k);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,u,v,k=0;
    cin>>n>>m;
    while (m--)
    {
        cin>>u>>v;
        e1[u].push_back(v);
        e2[v].push_back(u);
    }
    for (int i=1;i<=n;++i)
        if (!done[i])
            dfs1(i);
    done.reset();
    while (!s.empty())
    {
        if (done[s.top()])
        {
            s.pop();
            continue;
        }
        dfs2(s.top(),++k);
        s.pop();
    }
    cout<<k<<"\n";
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    return 0;
}
