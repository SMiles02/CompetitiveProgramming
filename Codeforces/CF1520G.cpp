#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e3+4;
const ll INF = 1e18;
int a[N][N],w;
ll d[2][N][N];
vector<array<int,2>> e[N][N];
vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};

void bfs(int c, int x, int y)
{
    for (int i=0;i<N;++i)
        for (int j=0;j<N;++j)
            d[c][i][j]=INF;
    queue<array<int,2>> q;
    d[c][x][y]=0;
    q.push({x,y});
    while (!q.empty())
    {
        x=q.front()[0];
        y=q.front()[1];
        q.pop();
        for (auto i : e[x][y])
            if (d[c][i[0]][i[1]]==INF)
            {
                d[c][i[0]][i[1]]=d[c][x][y]+w;
                q.push({i[0],i[1]});
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m>>w;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            cin>>a[i][j];
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (a[i][j]!=-1)
                for (int k=0;k<4;++k)
                    if (0<=i+dx[k]&&i+dx[k]<n&&0<=j+dy[k]&&j+dy[k]<m)
                        if (a[i+dx[k]][j+dy[k]]!=-1)
                            e[i][j].push_back({i+dx[k],j+dy[k]});
    bfs(0,0,0);
    bfs(1,n-1,m-1);
    ll ans,x=INF,y=INF;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (a[i][j]>0)
            {
                x=min(x,d[0][i][j]+a[i][j]);
                y=min(y,d[1][i][j]+a[i][j]);
            }
    ans=min(x+y,d[1][0][0]);
    if (ans==INF)
        ans=-1;
    cout<<ans;
    return 0;
}