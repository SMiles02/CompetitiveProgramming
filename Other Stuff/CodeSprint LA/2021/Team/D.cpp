#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e4+1;
int n;
vector<int> e[2][N];
vector<int> v[2];
bitset<N> done, O[2][N];

void make(int i, int x, int y, int z)
{
    O[i][x][y]=z;
    O[i][y][x]=z;
}

void dfs(int c, int p, int x, int y, int z)
{
    if (sz(v[z])>n*50)
        return;
    cout<<c<<" "<<x<<" "<<y<<"\n";
    for (auto i : e[z][c])
        if (i!=p)
        {
            if (x==y) //done
            {
                dfs(i,c,O[z][c][i],1,z);
                make(z,c,i,1);
            }
            else if (x==0&&y==1) //1 flip
            {
                if (O[z][c][i]==1)
                    dfs(i,c,1,0,z);
                make(z,c,i,0);
            }
            else if (x==1&&y==0) //multiflip
            {
                if (O[z][c][i]==0)
                    dfs(i,c,0,1,z);
                make(z,c,i,1);
            }
        }
    if (sz(v[z])>n*50)
        return;
    if (x!=y)
    {
        v[z].push_back(c);
        cout<<c<<"\n";
        for (auto i : e[z][c])
            if (i!=p)
            {
                make(z,c,i,y);
                dfs(i,c,O[z][c][i],1,z);
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x,y,z,r;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y>>z;
        e[0][x].push_back(y);
        e[0][y].push_back(x);
        e[1][x].push_back(y);
        e[1][y].push_back(x);
        make(0,x,y,z);
        make(1,x,y,z);
    }
    queue<array<int,2>> q;
    for (int i=1;i<=n;++i)
        if (sz(e[0][i])==1)
        {
            done[i]=1;
            q.push({i,0});
        }
    while (!q.empty())
    {
        x=q.front()[0];
        y=q.front()[1];
        q.pop();
        for (auto i : e[0][x])
            if (i!=y&&!done[i])
            {
                done[i]=1;
                q.push({i,x});
            }
    }
    r=x;
    for (auto i : e[0][r])
        dfs(i,r,O[0][r][i],0,0);
    for (auto i : e[1][r])
        dfs(i,r,O[1][r][i],1,1);
    v[0].push_back(r);
    cout<<min(sz(v[0]),sz(v[1]))<<"\n";
    if (sz(v[0])<sz(v[1]))
        for (int i : v[0])
            cout<<i<<"\n";
    else
        for (int i : v[1])
            cout<<i<<"\n";
    return 0;
}