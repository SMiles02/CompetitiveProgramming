#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5+1;
int k, sub[N], dp[N];
long long ans;
vector<int> e[N];
bitset<N> black;
 
void dfs(int c, int p)
{
    sub[c]=1;
    for (int i : e[c])
        if (i!=p&&!black[i])
        {
            dfs(i,c);
            sub[c]+=sub[i];
        }
}
 
int findC(int c, int p, int t)
{
    for (int i : e[c])
        if (i!=p&&!black[i]&&sub[i]>t)
            return findC(i,c,t);
    return c;
}
 
void dfsCheck(int c, int p, int h, int t)
{
    if (h<=k&&k-h<=t)
        ans+=dp[k-h];
    for (int i : e[c])
        if (i!=p&&!black[i])
            dfsCheck(i,c,h+1,t);
}
 
void dfsAdd(int c, int p, int h, int t)
{
    if (h<=k)
        ++dp[h];
    for (int i : e[c])
        if (i!=p&&!black[i])
            dfsAdd(i,c,h+1,t);
}
 
void solve(int r)
{
    dfs(r,0);
    int c = findC(r,0,sub[r]/2);
    for (int i=1;i<=sub[r];++i)
        dp[i]=0;
    dp[0]=1;
    black[c]=1;
    for (int i : e[c])
        if (!black[i])
        {
            dfsCheck(i,c,1,sub[r]);
            dfsAdd(i,c,1,sub[r]);
        }
    for (int i : e[c])
        if (!black[i])
            solve(i);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y;
    cin>>n>>k;
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