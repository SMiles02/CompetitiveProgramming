#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define a3 array<int,3>
using namespace std;

const int N = 1001, INF = 1e9;
vector<int> e[N][26];
int d[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y,ans=1e9;
    cin>>n>>m;
    char c;
    while (m--)
    {
        cin>>x>>y>>c;
        e[x][c-'a'].push_back(y);
        e[y][c-'a'].push_back(x);
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            d[i][j]=INF;
    d[1][n]=0;
    priority_queue<a3,vector<a3>,greater<a3>> pq;
    pq.push({0,1,n});
    while (!pq.empty())
    {
        a3 a = pq.top();
        pq.pop();
        x=a[1];y=a[2];
        if (d[x][y]!=a[0]||x==y)
            continue;
        for (int l=0;l<26;++l)
            for (int i : e[x][l])
            {
                if (i==y)
                {
                    d[y][y]=min(d[y][y],d[x][y]+1);
                    d[x][x]=min(d[x][x],d[x][y]+1);
                }
                for (int j : e[y][l])
                    if (d[x][y]+2<d[i][j])
                    {
                        d[i][j]=d[x][y]+2;
                        pq.push({d[i][j],i,j});
                    }
            }
    }
    for (int i=1;i<=n;++i)
        ans=min(ans,d[i][i]);
    if (ans==INF)
        ans=-1;
    cout<<ans;
    return 0;
}