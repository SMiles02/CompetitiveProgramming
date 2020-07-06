#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int ans=0;
string inp;

int visited[7][7];

void permGen(int x, int y, int c, int d, int cur, char s)
{
    if (inp[cur-2]!='?'&&s!=inp[cur-2])
        return;
    if (cur==49)
    {
        ++ans;
        return;
    }
    if (x==6&&y==0)
        return;
    if (c==x-1)
    {
        if (x<6)
        {
            if (y>0&&y<6)
            {
                if (visited[x+1][y]&&!visited[x][y+1]&&!visited[x][y-1])
                    return;
            }
        }
        else
        {
            if (y>0&&y<6)
            {
                if (!visited[x][y+1]&&!visited[x][y-1])
                    return;
            }
        }
    }
    if (c==x+1)
    {
        if (x>0)
        {
            if (y>0&&y<6)
            {
                if (visited[x-1][y]&&!visited[x][y+1]&&!visited[x][y-1])
                    return;
            }
        }
        else
        {
            if (y>0&&y<6)
            {
                if (!visited[x][y+1]&&!visited[x][y-1])
                    return;
            }
        }
    }
    if (d==y-1)
    {
        if (y<6)
        {
            if (x>0&&x<6)
            {
                if (visited[x][y+1]&&!visited[x+1][y]&&!visited[x-1][y])
                    return;
            }
        }
        else
        {
            if (x>0&&x<6)
            {
                if (!visited[x+1][y]&&!visited[x-1][y])
                    return;
            }
        }
    }
    if (d==y+1)
    {
        if (y>0)
        {
            if (x>0&&x<6)
            {
                if (visited[x][y-1]&&!visited[x+1][y]&&!visited[x-1][y])
                    return;
            }
        }
        else
        {
            if (x>0&&x<6)
            {
                if (!visited[x+1][y]&&!visited[x-1][y])
                    return;
            }
        }
    }
    if (x<6&&!visited[x+1][y])
    {
        visited[x+1][y]=1;
        permGen(x+1,y,x,y,cur+1,'D');
        visited[x+1][y]=0;
    }
    if (x>0&&!visited[x-1][y])
    {
        visited[x-1][y]=1;
        permGen(x-1,y,x,y,cur+1,'U');
        visited[x-1][y]=0;
    }
    if (y<6&&!visited[x][y+1])
    {
        visited[x][y+1]=1;
        permGen(x,y+1,x,y,cur+1,'R');
        visited[x][y+1]=0;
    }
    if (y>0&&!visited[x][y-1])
    {
        visited[x][y-1]=1;
        permGen(x,y-1,x,y,cur+1,'L');
        visited[x][y-1]=0;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>inp;
    visited[0][0]=1;
    visited[0][1]=1;
    permGen(0,1,0,0,2,'R');
    visited[0][1]=0;
    visited[1][0]=1;
    permGen(1,0,0,0,2,'D');
    cout<<ans;
    return 0;
}