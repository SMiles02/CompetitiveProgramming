#include <bits/stdc++.h>
using namespace std;

int n, a[500][500], f[501];
vector<int> dx = {0,1,0,-1};
vector<int> dy = {-1,0,1,0};

bool ok(int x, int y)
{
    if (0<=x&&0<=y&&y<=x&&a[x][y]==0)
        return 1;
    return 0;
}

void dfs(int x, int y)
{
    for (int i=0;f[a[x][y]]<a[x][y]&&i<4;++i)
        if (ok(x+dx[i],y+dy[i]))
        {
            a[x+dx[i]][y+dy[i]]=a[x][y];
            ++f[a[x][y]];
            dfs(x+dx[i],y+dy[i]);
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i][i],f[i+1]=1;
    for (int i=0;i<n;++i)
        dfs(i,i);
    for (int i=0;i<n;++i)
        for (int j=0;j<=i;++j)
            if (a[i][j]==0)
            {
                cout<<-1;
                return 0;
            }
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<=i;++j)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}