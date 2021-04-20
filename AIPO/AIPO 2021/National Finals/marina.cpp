#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int a[N][N],n,m,k,ans;
bitset<N> done[N];
vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};

bool ok(int x, int y)
{
    if (0<=x&&0<=y&&x<n&&y<m&&a[x][y]==1&&done[x][y]==0)
        return 1;
    return 0;
}

void dfs(int x, int y)
{
    ++k;
    done[x][y]=1;
    for (int i=0;i<4;++i)
        if (ok(x+dx[i],y+dy[i]))
            dfs(x+dx[i],y+dy[i]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            cin>>a[i][j];
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (ok(i,j))
            {
                k=0;
                dfs(i,j);
                ans += min((int)(k>1),1);
            }
    cout<<ans;
    return 0;
}