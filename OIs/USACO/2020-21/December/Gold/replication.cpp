#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int INF = 1e9+69;

int n,d,dist[1000][1000],t[1000][1000];
string s[1000];
bitset<1000> d1[1000], d2[1000], d3[1000];
vector<int> dx = {0,0,1,-1};
vector<int> dy = {-1,1,0,0};

bool ok(int x, int y, bitset<1000> done[])
{
    if (0<=x&&0<=y&&x<n&&y<n&&!done[x][y]&&s[x][y]!='#')
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x,y,ans=0;
    cin>>n>>d;
    for (int i=0;i<n;++i)
        cin>>s[i];
    queue<pii> q;
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            if (s[i][j]=='#')
                q.push({i,j});
    while (!q.empty())
    {
        x=q.front().f;y=q.front().s;
        q.pop();
        for (int i=0;i<4;++i)
            if (ok(x+dx[i],y+dy[i],d1))
            {
                q.push({x+dx[i],y+dy[i]});
                d1[x+dx[i]][y+dy[i]]=1;
                dist[x+dx[i]][y+dy[i]]=dist[x][y]+1;
            }
    }
    /**for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
            cout<<dist[i][j];
        cout<<"\n";
    }**/
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
        {
            t[i][j]=INF;
            if (s[i][j]=='S')
            {
                q.push({i,j});
                t[i][j]=0;
                d2[i][j]=1;
            }
        }
    while (!q.empty())
    {
        x=q.front().f;y=q.front().s;
        q.pop();
        if (dist[x][y]<=(t[x][y]/d))
            continue;
        for (int i=0;i<4;++i)
            if (ok(x+dx[i],y+dy[i],d2))
            {
                q.push({x+dx[i],y+dy[i]});
                d2[x+dx[i]][y+dy[i]]=1;
                t[x+dx[i]][y+dy[i]]=min(t[x+dx[i]][y+dy[i]],t[x][y]+1);
            }
    }
    /**cout<<"\n";
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
        {
            if (t[i][j]==INF)
                cout<<"N";
            else
                cout<<t[i][j];
        }
        cout<<"\n";
    }**/
    for (x=0;x<n;++x)
        for (y=0;y<n;++y)
            if (t[x][y]<INF)
            {
                d3[x][y]=1;
                if (t[x][y]>=d&&dist[x][y]>1)
                    for (int i=0;i<4;++i)
                        if (ok(x+dx[i],y+dy[i],d3))
                            d3[x+dx[i]][y+dy[i]]=1;
            }
    //cout<<"\n";
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
        {
            if (d3[i][j])
                ++ans;
            //cout<<d3[i][j];
        }
        //cout<<"\n";
    }
    cout<<ans;
    return 0;
}