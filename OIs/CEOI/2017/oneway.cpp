#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5+3, K = 5, L = __lg(N*K)+2;
int n, edgeList[N][2], tin[N], low[N], t, p[N][2], cur, dp[N*K], P[N*K];
vector<int> bct[N*K];
vector<array<int,2>> e[N];
map<array<int,2>,int> mp;
string ans(N, 'B');
bitset<N> d1, d2, ap;
bitset<N*K> d3;
set<int> s[N];
 
void dfs(int c, int pt, int pi)
{
    p[c][0]=pt;
    p[c][1]=pi;
    d1[c]=1;
    tin[c]=low[c]=++t;
    vector<int> v;
    for (auto i : e[c])
        if (i[1]!=pi)
        {
            if (d1[i[0]])
                low[c]=min(low[c],tin[i[0]]);
            else
            {
                dfs(i[0],c,i[1]);
                low[c]=min(low[c],low[i[0]]);
                if (pt==0)
                    v.push_back(i[0]);
                else if (tin[c]<=low[i[0]])
                {
                    ap[c]=1;
                    s[c].insert(i[0]);
                }
            }
        }
    if (pt==0&&v.size()>1)
    {
        ap[c]=1;
        for (int i : v)
            if (tin[c]<low[i])
                s[c].insert(i);
    }
}
 
void buildBCT(int c, int gp)
{
    bct[c].push_back(gp);
    bct[gp].push_back(c);
    d2[c]=1;
    for (auto i : e[c])
        if (!d2[i[0]])
        {
            if (ap[c]&&s[c].count(i[0]))
            {
                ++cur;
                bct[c].push_back(cur);
                bct[cur].push_back(c);
                buildBCT(i[0],cur);
            }
            else
                buildBCT(i[0],gp);
        }
}
 
void dfsAns(int c, int pt)
{
    //cout<<c<<": "<<pt<<"\n";
    d3[c]=1;
    P[c]=pt;
    for (int i : bct[c])
        if (!d3[i])
        {
            dfsAns(i,c);
            dp[c]+=dp[i];
        }
    //cout<<c<<": "<<dp[c]<<"\n";
    if (c>n||bct[pt].size()>2)
        return;
    int i = mp[{c,P[pt]}];
    if (dp[c]>0)
    {
        if (c==edgeList[i][0])
            ans[i]='R';
        else
            ans[i]='L';
    }
    else if (dp[c]<0)
    {
        if (c==edgeList[i][0])
            ans[i]='L';
        else
            ans[i]='R';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m,x,y,q;
    cin>>n>>m;
    for (int i=1;i<=m;++i)
    {
        cin>>x>>y;
        mp[{x,y}]=mp[{y,x}]=i;
        edgeList[i][0]=x;
        edgeList[i][1]=y;
        e[x].push_back({y,i});
        e[y].push_back({x,i});
    }
    cur=n;
    for (int i=1;i<=n;++i)
        if (!d1[i])
        {
            dfs(i,0,0);
            buildBCT(i,++cur);
        }
    cin>>q;
    while (q--)
    {
        cin>>x>>y;
        ++dp[x];
        --dp[y];
    }
    for (int i=1;i<=n;++i)
        if (!d3[i])
            dfsAns(i,0);
    for (int i=1;i<=m;++i)
        cout<<ans[i];
    return 0;
}