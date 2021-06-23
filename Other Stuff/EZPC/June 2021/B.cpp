#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n,m;
bitset<N> done[N];
string s[N];
long long ans;

bool ok(int x, int y)
{
    if (0<=x&&0<=y&&x<n&&y<m&&!done[x][y])
        return 1;
    return 0;
}

void dfs(int x, int y, int z)
{
    done[x][y]=1;
    int X,Y;
    if (s[x][y]=='v'&&ok(x+1,y))
    {
        X=x+1;
        Y=y;
        if (s[X][Y]=='^')
        {
            ans+=z;
            --z;
            s[X][Y]='v';
        }
        if (s[X][Y]=='v')
            dfs(X,Y,z+1);
    }
    if (s[x][y]=='^'&&ok(x-1,y))
    {
        X=x-1;
        Y=y;
        if (s[X][Y]=='v')
        {
            ans+=z;
            --z;
            s[X][Y]='^';
        }
        if (s[X][Y]=='^')
            dfs(X,Y,z+1);
    }
    if (s[x][y]=='>'&&ok(x,y+1))
    {
        X=x;
        Y=y+1;
        if (s[X][Y]=='<')
        {
            ans+=z;
            --z;
            s[X][Y]='>';
        }
        if (s[X][Y]=='>')
            dfs(X,Y,z+1);
    }
    if (s[x][y]=='<'&&ok(x,y-1))
    {
        X=x;
        Y=y-1;
        if (s[X][Y]=='>')
        {
            ans+=z;
            --z;
            s[X][Y]='<';
        }
        if (s[X][Y]=='<')
            dfs(X,Y,z+1);
    }
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (!done[i][j]&&(s[i][j]=='v'||s[i][j]=='>'))
                dfs(i,j,1);
    cout<<ans;
    return 0;
}