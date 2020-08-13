#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,q,v,k,up[200001][19];
vector<int> children[200001];

void dfs(int c, int p)
{
    up[c][0]=p;
    for (int i=1;i<19;++i)
        up[c][i]=up[up[c][i-1]][i-1];
    for (int i : children[c])
        dfs(i,c);
}

int lift(int x, int y)
{
    for (int i=0;i<19;++i)
        if (((1<<i)&y))
        {
            x=up[x][i];
            y-=(1<<i);
        }
    if (x==0)
        return -1;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    for (int i=2;i<=n;++i)
    {
        cin>>v;
        children[v].push_back(i);
    }
    dfs(1,0);
    while (q--)
    {
        cin>>v>>k;
        cout<<lift(v,k)<<"\n";
    }
    return 0;
}