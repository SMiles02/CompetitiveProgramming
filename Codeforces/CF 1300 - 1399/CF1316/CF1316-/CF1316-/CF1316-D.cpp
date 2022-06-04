#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,cur,doneNums=0;
vector<vector<pair<int,int>>> target;
map<pair<int,int>,int> done;
pair<int,int> origin;
map<pair<int,int>,char> final;

void dfsINFINITY(int x, int y)
{
    ++cur;
    ++doneNums;
    done[{x,y}]=1;
    if (x)
    {
        if (done[{x-1,y}]==0&&target[x-1][y].first==-1)
        {
            final[{x-1,y}]='D';
            if (origin==make_pair(x,y))
            {
                final[{x,y}]='U';
            }
            dfsINFINITY(x-1,y);
        }
    }
    if (x+1<n)
    {
        if (done[{x+1,y}]==0&&target[x+1][y].first==-1)
        {
            final[{x+1,y}]='U';
            if (make_pair(x,y)==origin)
            {
                final[{x,y}]='D';
            }
            dfsINFINITY(x+1,y);
        }
    }
    if (y)
    {
        if (done[{x,y-1}]==0&&target[x][y-1].first==-1)
        {
            final[{x,y-1}]='R';
            if (make_pair(x,y)==origin)
            {
                final[{x,y}]='L';
            }
            dfsINFINITY(x,y-1);
        }
    }
    if (y+1<n)
    {
        if (done[{x,y+1}]==0&&target[x][y+1].first==-1)
        {
            final[{x,y+1}]='L';
            if (make_pair(x,y)==origin)
            {
                final[{x,y}]='R';
            }
            dfsINFINITY(x,y+1);
        }
    }
}

void dfs(int x, int y)
{
    //cout<<x<<" "<<y<<" - entered\n";
    ++doneNums;
    done[{x,y}]=1;
    if (make_pair(x,y)==origin)
    {
        final[{x,y}]='X';
    }
    if (x>0)
    {
        if (done[{x-1,y}]==0&&target[x-1][y]==origin)
        {
            final[{x-1,y}]='D';
            dfs(x-1,y);
        }
    }
    if (x+1<n)
    {
        if (done[{x+1,y}]==0&&target[x+1][y]==origin)
        {
            final[{x+1,y}]='U';
            dfs(x+1,y);
        }
    }
    if (y>0)
    {
        if (done[{x,y-1}]==0&&target[x][y-1]==origin)
        {
            final[{x,y-1}]='R';
            dfs(x,y-1);
        }
    }
    if (y+1<n)
    {
        if (done[{x,y+1}]==0&&target[x][y+1]==origin)
        {
            final[{x,y+1}]='L';
            dfs(x,y+1);
        }
    }
    //cout<<x<<" "<<y<<" exitted\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x,y;
    vector<pair<int,int>> v;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        v.clear();
        for (int j=0;j<n;++j)
        {
            cin>>x>>y;
            v.push_back({max(-1,x-1),max(-1,y-1)});
        }
        target.push_back(v);
    }
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
        {
            if (!done[{i,j}])
            {
                if (target[i][j].first==-1)
                {
                    //cout<<"test\n";
                    cur=0;
                    origin={i,j};
                    dfsINFINITY(i,j);
                    if (cur==1)
                    {
                        cout<<"INVALID";
                        return 0;
                    }
                }
                else if (i==target[i][j].first&&j==target[i][j].second)
                {
                    origin={i,j};
                    dfs(i,j);
                }
            }
        }
    }
    if (doneNums!=n*n)
    {
        cout<<"INVALID";
        return 0;
    }
    cout<<"VALID\n";
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
        {
            cout<<final[{i,j}];
        }
        cout<<"\n";
    }
    return 0;
}