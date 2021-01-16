#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 2000;
int n,m,dist[mn][mn];
string s[mn];
bitset<mn> done[mn];
array<int,2> origin[mn][mn];
deque<array<int,5>> pq;

bool ok(int x, int y)
{
    if (0<=x&&x<n&&0<=y&&y<m&&!done[x][y])
        return 1;
    return 0;
}

void U(int x, int y, int z)
{
    if (ok(x-1,y))
    {
        if (s[x][y]=='^'||s[x][y]=='o')
            pq.push_front({x-1,y,z,x,y});
        else
            pq.push_back({x-1,y,z+1,x,y});
    }
}

void D(int x, int y, int z)
{
    if (ok(x+1,y))
    {
        if (s[x][y]=='v'||s[x][y]=='o')
            pq.push_front({x+1,y,z,x,y});
        else
            pq.push_back({x+1,y,z+1,x,y});
    }
}

void L(int x, int y, int z)
{
    if (ok(x,y-1))
    {
        if (s[x][y]=='<'||s[x][y]=='o')
            pq.push_front({x,y-1,z,x,y});
        else
            pq.push_back({x,y-1,z+1,x,y});
    }
}

void R(int x, int y, int z)
{
    if (ok(x,y+1))
    {
        if (s[x][y]=='>'||s[x][y]=='o')
            pq.push_front({x,y+1,z,x,y});
        else
            pq.push_back({x,y+1,z+1,x,y});
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    int a,b,c,d;
    for (int i=0;i<n;++i)
    {
        cin>>s[i];
        for (int j=0;j<m;++j)
        {
            if (s[i][j]=='o')
            {
                a=i;
                b=j;
            }
            if (s[i][j]=='x')
            {
                c=i;
                d=j;
            }
        }
    }
    pq.push_front({a,b,0,a,b});
    array<int,5> l;
    while (!pq.empty())
    {
        l=pq.front();
        pq.pop_front();
        if (!done[l[0]][l[1]])
        {
            done[l[0]][l[1]]=1;
            dist[l[0]][l[1]]=l[2];
            origin[l[0]][l[1]]={l[3],l[4]};
            U(l[0],l[1],l[2]);
            D(l[0],l[1],l[2]);
            L(l[0],l[1],l[2]);
            R(l[0],l[1],l[2]);
        }
    }
    cout<<dist[c][d]<<"\n";
    array<int,2> A={c,d};
    while (A[0]!=a||A[1]!=b)
    {
        if (origin[A[0]][A[1]][0]==a&&origin[A[0]][A[1]][1]==b)
            break;
        if (origin[A[0]][A[1]][0]==A[0]-1&&origin[A[0]][A[1]][1]==A[1])
            s[origin[A[0]][A[1]][0]][origin[A[0]][A[1]][1]]='v';
        if (origin[A[0]][A[1]][0]==A[0]+1&&origin[A[0]][A[1]][1]==A[1])
            s[origin[A[0]][A[1]][0]][origin[A[0]][A[1]][1]]='^';
        if (origin[A[0]][A[1]][0]==A[0]&&origin[A[0]][A[1]][1]==A[1]-1)
            s[origin[A[0]][A[1]][0]][origin[A[0]][A[1]][1]]='>';
        if (origin[A[0]][A[1]][0]==A[0]&&origin[A[0]][A[1]][1]==A[1]+1)
            s[origin[A[0]][A[1]][0]][origin[A[0]][A[1]][1]]='<';
        A=origin[A[0]][A[1]];
    }
    for (int i=0;i<n;++i)
        cout<<s[i]<<"\n";
    return 0;
}