#include <bits/stdc++.h>
#define a3 array<int,3>
using namespace std;

const int N = 505, INF = 1e9+7;
int a[N][N], b[N][N], d[N][N];
priority_queue<a3,vector<a3>,greater<a3>> pq;

void add(int x, int y)
{
    pq.push({d[x][y],x,y});
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int r,c,x,y,z;
    cin>>r>>c;
    for (int i=1;i<=r;++i)
        for (int j=1;j<c;++j)
            cin>>a[i][j];
    for (int i=1;i<r;++i)
        for (int j=1;j<=c;++j)
            cin>>b[i][j];
    for (int i=1;i<=r;++i)
        for (int j=1;j<=c;++j)
            d[i][j]=INF;
    d[1][1]=0;
    add(1,1);
    while (!pq.empty())
    {
        x=pq.top()[1];
        y=pq.top()[2];
        z=pq.top()[0];
        pq.pop();
        if (z>d[x][y])
            continue;
        if (y<c&&z+a[x][y]<d[x][y+1])
        {
            d[x][y+1]=z+a[x][y];
            add(x,y+1);
        }
        if (y>1&&z+a[x][y-1]<d[x][y-1])
        {
            d[x][y-1]=z+a[x][y-1];
            add(x,y-1);
        }
        if (x<r&&z+b[x][y]<d[x+1][y])
        {
            d[x+1][y]=z+b[x][y];
            add(x+1,y);
        }
        for (int i=1;i<x;++i)
            if (z+i+1<d[x-i][y])
            {
                d[x-i][y]=z+i+1;
                add(x-i,y);
            }
    }
    cout<<d[r][c];
    return 0;
}