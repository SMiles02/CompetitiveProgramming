#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+1;
vector<int> edges[maxn],col[2],cycle;
int parent[maxn],r[maxn];
bitset<maxn> done;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    r[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (r[a] < r[b])
            swap(a, b);
        parent[b] = a;
        r[a] += r[b];
    }
}

bool dfsCycle(int c, int p, int t)
{
    if (c==t)
    {
        cycle.push_back(c);
        return 1;
    }
    for (int i : edges[c])
        if (i!=p)
        {
            if (dfsCycle(i,c,t))
            {
                cycle.push_back(c);
                return 1;
            }
        }
    return 0;
}

void dfs(int c, int h)
{
    col[h].push_back(c);
    done[c]=1;
    for (int i : edges[c])
        if (!done[i])
            dfs(i,h^1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,u,v;
    cin>>n>>m>>k;
    for (int i=1;i<=k;++i)
        make_set(i);
    while (m--)
    {
        cin>>u>>v;
        if (u>k||v>k)
            continue;
        if (find_set(u)==find_set(v))
        {
            dfsCycle(u,0,v);
            cout<<"2\n"<<cycle.size()<<"\n";
            for (int i : cycle)
                cout<<i<<" ";
            return 0;
        }
        edges[u].push_back(v);
        edges[v].push_back(u);
        union_sets(u,v);
    }
    cout<<"1\n";
    vector<int> ans;
    for (int i=1;i<=k;++i)
        if (!done[i])
        {
            for (int i=0;i<2;++i)
                col[i].clear();
            dfs(i,0);
            if (col[0].size()<col[1].size())
                for (int i : col[1])
                    ans.push_back(i);
            else
                for (int i : col[0])
                    ans.push_back(i);
        }
    for (int i=0;i<(k+1)/2;++i)
        cout<<ans[i]<<" ";
    return 0;
}