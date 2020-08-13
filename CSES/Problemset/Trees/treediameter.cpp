#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,x,y;
vector<int> edges[200001];

void dfs(int c, int p, int h)
{
    if (h>x)
    {
        x=h;
        y=c;
    }
    for (int i : edges[c])
        if (i!=p)
            dfs(i,c,h+1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    x=0;
    dfs(1,0,0);
    dfs(y,0,0);
    cout<<x;
    return 0;
}