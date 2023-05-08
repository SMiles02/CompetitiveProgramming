#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
int n, sub[N];
vector<int> e[N];
bitset<N> black;

int subDfs(int c, int p)
{
    sub[c]=1;
    for (int i : e[c])
        if (i!=p&&!black[i])
            sub[c]+=subDfs(i,c);
    return sub[c];
}

int findCentroid(int c, int p, int t)
{
    for (int i : e[c])
        if (!black[i]&&i!=p&&sub[i]>t)
            return findCentroid(i,c,t);
    return c;
}

void dfs(int c, int p, int h)
{
    // check for whatever the problem asks
    for (int i : e[c])
        if (i!=p)
            dfs(i,c,h+1);
}

void solve(int x)
{
    int c = findCentroid(x,0,subDfs(x,0)/2);
    black[c]=1;
    for (int i : e[c])
        if (!black[i])
            dfs(i,c,1);
    for (int i : e[c])
        if (!black[i])
            solve(i);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x,y;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    solve(1);
    cout<<ans;
    return 0;
}