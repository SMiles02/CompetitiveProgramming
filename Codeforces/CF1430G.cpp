#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int maxn=19;
int n,ans[maxn],edges[maxn][maxn],from[maxn];
int score,tpScore,prev;

void calc()
{
    tpScore=0;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            tpScore+=((ans[i]-ans[j])*edges[i][j]);
}

void checkChange(int k)
{
    for (int i=0;i<20;++i)
        if (k&(1<<i))
            ++ans[i+1];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            if (edges[i][j]&&ans[i]<=ans[j])
            {
                for (int x=0;x<20;++x)
                    if (k&(1<<x))
                        --ans[x+1];
                return;
            }
    calc();
    if (tpScore>=score)
    {
        for (int i=0;i<20;++i)
            if (k&(1<<i))
                --ans[i+1];
    }
    else
        score=tpScore;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m,x,y,w;
    cin>>n>>m;
    for (int i=0;i<m;++i)
    {
        cin>>x>>y>>w;
        edges[x][y]=w;
        ++from[x];
    }
    stack<int> s;
    for (int i=1;i<=n;++i)
        if (from[i]==0)
            s.push(i);
    while (!s.empty())
    {
        x=s.top();
        s.pop();
        for (int i=1;i<=n;++i)
            if (edges[x][i])
                ans[x]=max(ans[x],ans[i]+1);
        for (int i=1;i<=n;++i)
            if (edges[i][x])
            {
                --from[i];
                if (from[i]==0)
                    s.push(i);
            }
    }
    calc();
    score=tpScore;
    for (int i=0;i<n;++i)
        for (int j=(1<<n)-1;j;--j)
            checkChange(j);
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    return 0;
}