#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5+1;
int col[N],f[N];
bitset<N> ans;
vector<int> edges[N];

void dfs(int c, int p)
{
    if (f[col[c]]==0)
        ans[c]=1;
    ++f[col[c]];
    for (int i : edges[c])
        if (i!=p)
            dfs(i,c);
    --f[col[c]];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y;
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>col[i];
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs(1,0);
    for (int i=1;i<=n;++i)
        if (ans[i])
            cout<<i<<"\n";
    return 0;
}