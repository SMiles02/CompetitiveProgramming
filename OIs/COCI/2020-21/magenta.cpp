#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 1e5+1, INF=1e9;
int a,b,heights[mn],dp[2237][2237][2];
bitset<3> done[2237][2237]; 
vector<array<int,2>> edges[mn];
vector<int> e[mn][3];
int ct[2237][2237][3];

//1 - drawn
//2 - lost
//3 - won

void smolCase()
{
    int x,y,z;
    queue<array<int,3>> q;
    array<int,3> ar;
    for (int i=1;i<=n;++i)
        if (sz(edges[i])==1)
        {
            dp[i][edges[i][0][0]][0]=2;
            dp[edges[i][0][0]][i][1]=2;
            q.push({i,edges[i][0][0],0});
            q.push({edges[i][0][0],i,1});
            done[i][edges[i][0][0]][0]=1
            done[edges[i][0][0]][i][1]=1;
        }
    while (!q.empty())
    {
        ar=q.front();
        q.pop();
        x=ar[0];
        y=ar[1];
        for (auto i : e[ar[ar[2]^1]][ar[2]^1])
        {
            if (ar[2])
                x=i;
            else
                y=i;
            z=i;
            if (!done[x][y][ar[2]^1])
            {
                if (dp[ar[0]][ar[1]][ar[2]]==2)
                {
                    dp[x][y][ar[2]^1]=1;
                    ct[x][y][ar[2]^1]=INF;
                    done[x][y][ar[2]^1]=1;
                    q.push({x,y,ar[2]^1});
                }
                else if (++ct[x][y][ar[2]^1]==sz(e[z][ar[2]^1]))
                {
                    q.push({x,y,ar[2]^1});
                    
                }
            }
        }
    }
    if (dp[a][b][0]==2)
        cout<<"Marin";
    else if (dp[a][b][0])
        cout<<"Paula";
    else
        cout<<"Magenta";
}

void edgeAdd(int x, int y, int z)
{
    edges[x].push_back({y,z});
    edges[y].push_back({x,z});
}

void dfs(int c, int p, int h)
{
    heights[c]=h;
    for (auto i : edges[c])
        if (i[0]!=p)
            dfs(i[0],c,h+1);
}

void allMCase()
{
    dfs(a,0,0);
    if (heights[b]&1)
        cout<<"Marin";
    else
        cout<<"Paula";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y;
    bool allM=1;
    string s;
    cin>>n;
    cin>>a>>b;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y>>s;
        if (s[0]=='p')
        {
            allM=0;
            edgeAdd(x,y,1);
            e[x][0].push_back(y);
            e[y][0].push_back(x);
        }
        else if (s[0]=='c')
        {
            allM=0;
            edgeAdd(x,y,2);
            e[x][1].push_back(y);
            e[y][1].push_back(x);
        }
        else
        {
            edgeAdd(x,y,3);
            e[x][1].push_back(y);
            e[y][1].push_back(x);
            e[x][0].push_back(y);
            e[y][0].push_back(x);
        }
    }
    if (allM)
        allMCase();
    else if (n<2237)
        smolCase();
    return 0;
}