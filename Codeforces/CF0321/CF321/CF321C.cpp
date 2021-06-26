#include <bits/stdc++.h>
using namespace std;

const int mn = 1e5+1;
string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int sub[mn];
set<int> black[mn];
vector<int> edges[mn];
char ans[mn];

void solve(int rt, int d);

void dfs(int c, int p)
{
    sub[c]=1;
    for (int i : edges[c])
        if (i!=p&&black[c].find(i)==black[c].end())
        {
            dfs(i,c);
            sub[c]+=sub[i];
        }
}

bool dfs(int c, int p, int rt, int d)
{
    int mx=sub[rt]-sub[c];
    for (int i : edges[c])
        if (i!=p&&black[c].find(i)==black[c].end())
        {
            if (dfs(i,c,rt,d))
                return 1;
            mx=max(mx,sub[i]);
        }
    if (mx<=sub[rt]/2)
    {
        ans[c]=alpha[d];
        for (int i : edges[c])
            if (black[c].find(i)==black[c].end())
            {
                black[i].insert(c);
                solve(i,d+1);
            }
        return 1;
    }
    return 0;
}

void solve(int rt, int d)
{
    dfs(rt,0);
    dfs(rt,0,rt,d);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    solve(1,0);
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    return 0;
}