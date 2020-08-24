#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MAXN=2e5+1;
vector<int> edges[MAXN];
int ans[MAXN],cur;

void dfs(int c, int x)
{
    ans[c]=x;
    ++cur;
    for (int i : edges[c])
        if (!ans[i])
            dfs(i,x^3);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,u,v;
    cin>>n>>m;
    for (int i=0;i<m;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int i=1;i<=n;++i)
        if (!ans[i])
        {
            cur=0;
            dfs(i,1);
            if (cur==1)
            {
                cout<<"NIE";
                return 0;
            }
        }
    cout<<"TAK\n";
    for (int i=1;i<=n;++i)
    {
        if (ans[i]==1)
            cout<<"K\n";
        else
            cout<<"S\n";
    }
    return 0;
}