#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define a2 array<int,2>
using namespace std;

const int N = 501;
int n,m,x,y,k,a[N][N],ans[N][N];
bitset<N> done[N];
vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};

bool ok(int X, int Y, int p, int s, int t)
{
    if (1<=X&&X<=n&&1<=Y&&Y<=m&&!done[X][Y]&&a[X][Y]%p==0&&a[X][Y]<a[s][t])
        return 1;
    return 0;
}

void solve(int p)
{
    done[x][y]=1;
    queue<a2> q;
    int c,d;
    q.push({x,y});
    while (!q.empty())
    {
        c=q.front()[0];
        d=q.front()[1];
        q.pop();
        ++ans[c][d];
        for (int i=0;i<4;++i)
            if (ok(c+dx[i],d+dy[i],p,c,d))
            {
                q.push({c+dx[i],d+dy[i]});
                done[c+dx[i]][d+dy[i]]=1;
            }
    }
    for (int i=1;i<=n;++i)
        done[i].reset();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    cin>>x>>y;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            cin>>a[i][j];
    k=a[x][y];
    for (int i=2;i*i<=k;++i)
        if (k%i==0)
        {
            solve(i);
            while (k%i==0)
                k/=i;
        }
    if (k>1)
        solve(k);
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
            cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}