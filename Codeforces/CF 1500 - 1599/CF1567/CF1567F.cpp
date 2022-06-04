#include <bits/stdc++.h>
using namespace std;

const int N = 500;
int n,m,ct[N][N],d[N][N];
string s[N];
vector<int> dx = {0,0,-1,1,-1,-1,1,1}, dy = {-1,1,0,0,-1,1,-1,1};

bool ok(int x, int y)
{
    return (0<=x&&0<=y&&x<n&&y<m);
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x,y,z,tX,tY,t;
    cin>>n>>m;
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
        {
            d[i][j]=1e9;
            if (s[i][j]=='X')
            {
                for (int k=0;k<4;++k)
                {
                    x=i+dx[k];
                    y=j+dy[k];
                    if (ok(x,y))
                        ct[i][j]+=(s[x][y]=='.');
                }
                if (ct[i][j]&1)
                {
                    cout<<"NO";
                    return 0;
                }
            }
        }
    cout<<"YES\n";
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
    d[0][0]=0;
    pq.push({0,0,0});
    while (!pq.empty())
    {
        x=pq.top()[1];
        y=pq.top()[2];
        z=pq.top()[0];
        pq.pop();
        if (d[x][y]<z)
            continue;
        for (int i=0;i<8;++i)
        {
            tX=x+dx[i];
            tY=y+dy[i];
            if (ok(tX,tY))
            {
                if (i>3&&(s[tX][tY]=='X'||s[x][y]!=s[tX][tY]))
                    continue;
                if (s[x][y]=='X'&&s[tX][tY]=='X'&&ct[x][y]==0)
                    t=2;
                else
                    t=0;
                if (z+t+(s[x][y]!=s[tX][tY])<d[tX][tY])
                {
                    d[tX][tY]=z+t+(s[x][y]!=s[tX][tY]);
                    pq.push({d[tX][tY],tX,tY});
                }
            }
        }
    }
    for (int i=0;i<n;++i)
    {
        z=0;
        for (int j=0;j<m;++j)
        {
            if (s[i][j]=='X')
                cout<<ct[i][j]/2*5<<" ";
            else if ((i+d[i][j]/2)&1)
                cout<<"1 ";
            else
                cout<<"4 ";
        }
        cout<<"\n";
    }
    return 0;
}