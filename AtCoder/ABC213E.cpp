#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 505;
int d[N][N], n, m, x, y;
string s[N];
bitset<N> done[N];
deque<array<int,2>> dq;

bool ok(int x, int y)
{
    return (x<n&&y<m&&0<=x&&0<=y);
}

void addD(int x, int y, int a, int b)
{
    if (a+b<d[x][y])
    {
        d[x][y]=a+b;
        if (b)
            dq.push_back({x,y});
        else
            dq.push_front({x,y});
    }
}

void check(int x, int y, int a)
{
    if (ok(x,y))
        addD(x,y,a,1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;++i)
    {
        cin>>s[i];
        for (int j=0;j<m;++j)
            d[i][j]=1e9;
    }
    d[0][0]=0;
    dq.push_back({0,0});
    while (!dq.empty())
    {
        x=dq[0][0];
        y=dq[0][1];
        dq.pop_front();
        if (done[x][y])
            continue;
        //cout<<x<<" "<<y<<" "<<d[x][y]<<"\n";
        done[x][y]=1;
        if (ok(x+1,y)&&s[x+1][y]=='.')
            addD(x+1,y,d[x][y],0);
        if (ok(x,y+1)&&s[x][y+1]=='.')
            addD(x,y+1,d[x][y],0);
        if (ok(x-1,y)&&s[x-1][y]=='.')
            addD(x-1,y,d[x][y],0);
        if (ok(x,y-1)&&s[x][y-1]=='.')
            addD(x,y-1,d[x][y],0);
        for (int i=-2;i<3;++i)
            for (int j=-2;j<3;++j)
                if (!(i==0&&j==0)&&!(abs(i)==2&&abs(j)==2))
                    check(x+i,y+j,d[x][y]);
    }
    cout<<d[n-1][m-1];
    return 0;
}