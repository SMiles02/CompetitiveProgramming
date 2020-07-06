#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m,ans=0;
string s[1000];

int done[1000][1000];

void dfs(int x, int y)
{
    done[x][y]=1;
    if (x-1>=0&&s[x-1][y]=='#'&&!done[x-1][y])
    {
        dfs(x-1,y);
    }
    if (x+1<n&&s[x+1][y]=='#'&&!done[x+1][y])
    {
        dfs(x+1,y);
    }
    if (y-1>=0&&s[x][y-1]=='#'&&!done[x][y-1])
    {
        dfs(x,y-1);
    }
    if (y+1<m&&s[x][y+1]=='#'&&!done[x][y+1])
    {
        dfs(x,y+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;++i)
        cin>>s[i];
    if (n==2&&m==1)
    {
        if (s[0][0]=='.'&&s[1][0]=='.')
            cout<<0;
        else if (s[0][0]=='#'&&s[1][0]=='#')
            cout<<1;
        else
            cout<<-1;
        return 0;
    }
    if (n==1&&m==2)
    {
        if (s[0][0]=='.'&&s[0][1]=='.')
            cout<<0;
        else if (s[0][0]=='#'&&s[0][1]=='#')
            cout<<1;
        else
            cout<<-1;
        return 0;
    }

    int flag,full,p1=0,p2=0;
    for (int i=0;i<n;++i)
    {
        full=1;
        if (s[i][0]=='#')
        {
            flag=1;
            full=0;
        }
        else 
            flag=0;
        for (int j=1;j<m;++j)
        {
            if (s[i][j]=='#'&&s[i][j-1]=='.')
                ++flag;
            if (s[i][j]=='#')
                full=0;
        }
        if (flag>1)
        {
            cout<<-1;
            return 0;
        }
        p1=max(p1,full);
    }
    for (int j=0;j<m;++j)
    {
        full=1;
        if (s[0][j]=='#')
        {
            flag=1;
            full=0;
        }
        else 
            flag=0;
        for (int i=1;i<n;++i)
        {
            if (s[i][j]=='#'&&s[i-1][j]=='.')
                ++flag;
            if (s[i][j]=='#')
                full=0;
        }
        if (flag>1)
        {
            cout<<-1;
            return 0;
        }
        p2=max(p2,full);
    }
    if (p1!=p2)
    {
        cout<<-1;
        return 0;
    }
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (s[i][j]=='#'&&!done[i][j])
            {
                ++ans;
                dfs(i,j);
            }
    cout<<ans;
    return 0;
}