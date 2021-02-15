#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m;
string s[1000],t[1000];
vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};
bitset<1000> done[4][1000];

bool ok(int x, int y, int z)
{
    if (0<=x&&0<=y&&x<n&&y<m&&!done[z][x][y])
        return 1;
    return 0;
}

void dfs(int x, int y, int z)
{
    //cout<<x<<" "<<y<<" "<<z<<"\n";
    t[x][y]='/';
    if (s[x][y]=='#')
    {
        for (int i=0;i<4;++i)
            done[i][x][y]=1;
        for (int i=0;i<4;++i)
            if (ok(x+dx[i],y+dy[i],i))
                dfs(x+dx[i],y+dy[i],i);
        return;
    }
    done[z][x][y]=1;
    if (ok(x+dx[z],y+dy[z],z))
        dfs(x+dx[z],y+dy[z],z);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;++i)
    {
        cin>>s[i];
        t[i]="";
        for (int j=0;j<m;++j)
            t[i]+='.';
    }
    s[0][0]='#';
    s[n-1][0]='#';
    s[0][m-1]='#';
    s[n-1][m-1]='#';
    dfs(0,0,0);
    /**for (int i=0;i<n;++i)
        cout<<t[i]<<"\n";
    cout<<"\n";**/
    int ans=0;
    set<int> x,y;
    bool b;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (s[i][j]=='#'&&!done[0][i][j])
            {
                ++ans;
                dfs(i,j,0);
                //cout<<i<<" "<<j<<"\n";
            }
    /**for (int i=0;i<n;++i)
        cout<<t[i]<<"\n";
    cout<<"\n";**/
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
        {
            b=1;
            for (int k=0;k<4;++k)
                if (done[k][i][j])
                    b=0;
            if (b)
            {
                //cout<<i<<" "<<j<<"\n";
                x.insert(i);
                y.insert(j);
            }
        }
    cout<<ans+min(sz(x),sz(y));
    return 0;
}