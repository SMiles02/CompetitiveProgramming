#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m, r[N][N], d[N][N];
string s[N];
vector<int> dx = {0,0,-1,1}, dy = {-1,1,0,0};

bool ok(int x, int y)
{
    if (0<=x&&0<=y&&x<n&&y<m)
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x,y;
    cin>>n>>m;
    deque<array<int,2>> dq;
    for (int i=0;i<n;++i)
    {
        cin>>s[i];
        for (int j=0;j<m;++j)
        {
            d[i][j]=1e9;
            if (s[i][j]=='M')
            {
                r[i][j]=2;
                dq.push_back({i,j});
            }
            if (s[i][j]=='A')
            {
                r[i][j]=1;
                x=i;y=j;
                d[i][j]=0;
            }
            if (s[i][j]=='#')
                r[i][j]=3;
        }
    }
    dq.push_back({x,y});
    while (!dq.empty())
    {
        x=dq.front()[0];
        y=dq.front()[1];
        dq.pop_front();
        if (r[x][y]==1)
        {
            if (x==0||y==0||x==n-1||y==m-1)
            {
                string ans="";
                cout<<"YES\n"<<d[x][y]<<"\n";
                while (d[x][y])
                    for (int i=0;i<4;++i)
                        if (ok(x+dx[i],y+dy[i]))
                            if (r[x+dx[i]][y+dy[i]]==1&&d[x+dx[i]][y+dy[i]]+1==d[x][y])
                            {
                                x+=dx[i];
                                y+=dy[i];
                                if (i==0)
                                    ans+="R";
                                if (i==1)
                                    ans+="L";
                                if (i==2)
                                    ans+="D";
                                if (i==3)
                                    ans+="U";
                            }
                while (!ans.empty())
                {
                    cout<<ans.back();
                    ans.pop_back();
                }
                return 0;
            }
            for (int i=0;i<4;++i)
                if (ok(x+dx[i],y+dy[i]))
                    if (r[x+dx[i]][y+dy[i]]==0)
                    {
                        dq.push_back({x+dx[i],y+dy[i]});
                        d[x+dx[i]][y+dy[i]]=d[x][y]+1;
                        r[x+dx[i]][y+dy[i]]=1;
                    }
        }
        else
            for (int i=0;i<4;++i)
                if (ok(x+dx[i],y+dy[i]))
                    if (r[x+dx[i]][y+dy[i]]==0)
                    {
                        dq.push_back({x+dx[i],y+dy[i]});
                        r[x+dx[i]][y+dy[i]]=2;
                    }
    }
    cout<<"NO";
    return 0;
}