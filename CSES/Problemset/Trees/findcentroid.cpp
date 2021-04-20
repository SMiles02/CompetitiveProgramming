#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+1;
int ans,n,sub[N];
vector<int> edges[N];

void dfs(int c, int p)
{
    int mx=0;
    sub[c]=1;
    for (int i : edges[c])
        if (i!=p)
        {
            dfs(i,c);
            sub[c]+=sub[i];
            mx=max(mx,sub[i]);
        }
    if (max(mx,n-sub[c])<=n/2)
        ans=c;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x,y;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}