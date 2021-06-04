#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int n, ct, sub[N], ans[N];
long long tot;
vector<int> e[N], v;

void dfs(int c, int p)
{
    int mx=0;
    sub[c]=1;
    for (int i : e[c])
        if (i!=p)
        {
            dfs(i,c);
            sub[c]+=sub[i];
            tot+=min(sub[i],n-sub[i])*2;
            mx=max(mx,sub[i]);
        }
    if (max(mx,n-sub[c])<=n/2)
        ct=c;
}

void dfsAns(int c, int p)
{
    v.push_back(c);
    for (int i : e[c])
        if (i!=p)
            dfsAns(i,c);
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
    dfs(1,0);
    dfsAns(ct,0);
    cout<<tot<<"\n";
    for (int i=0;i<n;++i)
        ans[v[i]]=v[(i+n/2)%n];
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    return 0;
}