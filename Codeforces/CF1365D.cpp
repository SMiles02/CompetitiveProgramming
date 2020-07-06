#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m;

bool ok(int x, int y)
{
    if (0<=x&&x<n&&0<=y&&y<m)
        return 1;
    return 0;
}

int dx[]={0,0,-1,1};
int dy[]={-1,+1,0,0};
string s[50];

void solve()
{
    int g=0;
    cin>>n>>m;
    for (int i=0;i<n;++i)
        cin>>s[i];
    bool done[n][m];
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            done[i][j]=0;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
        {
            if (s[i][j]=='B')
            {
                for (int k=0;k<4;++k)
                    if (ok(i+dx[k],j+dy[k])&&s[i+dx[k]][j+dy[k]]=='.')
                        s[i+dx[k]][j+dy[k]]='#';
            }
            else if (s[i][j]=='G')
                ++g;
        }
    if (s[n-1][m-1]=='#')
    {
        if (g)
            cout<<"No\n";
        else
            cout<<"Yes\n";
        return;
    }
    queue<pair<int,int>> q;
    q.push({n-1,m-1});
    done[n-1][m-1]=1;
    pair<int,int> p;
    while (sz(q))
    {
        int i=q.front().first,j=q.front().second;
        //cout<<i<<" "<<j<<":\n";
        q.pop();
        if (s[i][j]=='G')
            --g;
        if (s[i][j]=='B')
        {
            cout<<"No\n";
            return;
        }
        for (int k=0;k<4;++k)
        {
            //cout<<i+dx[k]<<" "<<j+dy[k]<<"\n";
            if (ok(i+dx[k],j+dy[k])&&s[i+dx[k]][j+dy[k]]!='#'&&!done[i+dx[k]][j+dy[k]])
            {
                q.push({i+dx[k],j+dy[k]});
                done[i+dx[k]][j+dy[k]]=1;
            }
        }
    }
    if (g!=0)
        cout<<"No\n";
    else
        cout<<"Yes\n";
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