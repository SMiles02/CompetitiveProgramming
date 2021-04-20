#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 405;
int n,m,a[N][N],d[N][N];
char c[N][N];
vector<int> dx = {-1,0,1,0};
vector<int> dy = {0,1,0,-1};

bool ok(int x, int y)
{
    if (1<=x&&1<=y&&x<=n&&y<=m)
        return 1;
    return 0;
}

void solve()
{
    int k,x,y;
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
        {
            cin>>a[i][j];
            d[i][j]=0;
        }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            cin>>c[i][j];
    priority_queue<array<int,3>> pq;
    pq.push({c[1][1],1,1});
    array<int,3> t;
    while (!pq.empty())
    {
        t=pq.top();
        pq.pop();
        x=t[1];y=t[2];
        if (t[0]!=d[x][y])
            continue;
        if (c[x][y]=='U')
            for (int i=0;i<4;++i)
                
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}