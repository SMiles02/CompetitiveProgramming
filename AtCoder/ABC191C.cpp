#include <bits/stdc++.h>
using namespace std;

int n,m,ans=0;
bitset<50> done[50];
string s[50],t[50],u(50,'.');
vector<int> dX = {0,0,1,-1};
vector<int> dY = {1,-1,0,0};

bool ok(int x, int y)
{
    if (0<=x&&0<=y&&x<4*n&&y<4*m&&t[x][y]=='#'&&done[x][y]==0)
        return 1;
    return 0;
}

bool landLocked(int x, int y)
{
    int sc=0;
    for (int i=0;i<4;++i)
        if (t[x+dX[i]][y+dY[i]]=='#')
            ++sc;
    if (sc==4)
        return 1;
    return 0;
}

void dfs(int x, int y, int cX, int cY)
{
    done[x][y]=1;
    for (int i=0;i<4;++i)
        if (ok(x+dX[i],y+dY[i])&&!landLocked(x+dX[i],y+dY[i]))
        {
            if (dX[i]!=cX||dY[i]!=cY)
                ++ans;
            dfs(x+dX[i],y+dY[i],dX[i],dY[i]);
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int i=0;i<4*n;++i)
        t[i]=u;
    for (int i=0;i<4*n;++i)
        for (int j=0;j<4*m;++j)
            t[i][j]=s[i/4][j/4];
    for (int i=0;i<4*n;++i)
        for (int j=0;j<4*m;++j)
            if (t[i][j]=='#'&&!done[i][j]&&!landLocked(i,j))
                dfs(i,j,0,-1);
    cout<<ans;
    return 0;
}