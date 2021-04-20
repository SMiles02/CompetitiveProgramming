#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mn = 10, X = 2e9;
string grid[mn];
int n,top[mn],bottom[mn],l[mn],r[mn];
vector<pii> v;

double rnd()
{
    return double(rng()%X)/X;
}

bool ok(int x, int y)
{
    if (x<0||y<0||x>=n||y>=n)
        return 0;
    return 1;
}

int dfs(int i, int j, int dX, int dY, bool mirrored)
{
    if (!ok(i,j))
        return 0;
    if (grid[i][j]=='Z')
        return 1 + dfs(i+dX,j+dY,dX,dY,mirrored);
    if (grid[i][j]=='V')
    {
        if (mirrored)
            return dfs(i+dX,j+dY,dX,dY,mirrored);
        return 1 + dfs(i+dX,j+dY,dX,dY,mirrored);
    }
    if (grid[i][j]=='G')
    {
        if (mirrored)
            return 1 + dfs(i+dX,j+dY,dX,dY,mirrored);
        return dfs(i+dX,j+dY,dX,dY,mirrored);
    }
    if (grid[i][j]=='/')
        return dfs(i-dY,j-dX,-dY,-dX,1);
    return dfs(i+dY,j+dX,dY,dX,1);
}

int calc()
{
    int ans=0;
    for (int i=0;i<n;++i)
        ans+=abs(top[i]-dfs(0,i,1,0,0));
    for (int i=0;i<n;++i)
        ans+=abs(bottom[i]-dfs(n-1,i,-1,0,0));
    for (int i=0;i<n;++i)
        ans+=abs(l[i]-dfs(i,0,0,1,0));
    for (int i=0;i<n;++i)
        ans+=abs(r[i]-dfs(i,n-1,0,-1,0));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int V,Z,G,a,b;
    cin>>V>>Z>>G;
    cin>>n;
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>top[i];
    for (int i=0;i<n;++i)
        cin>>bottom[i];
    for (int i=0;i<n;++i)
        cin>>l[i];
    for (int i=0;i<n;++i)
        cin>>r[i];
    for (int i=0;i<n;++i)
        cin>>grid[i];
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            if (grid[i][j]=='.')
                v.push_back({i,j});
    shuffle(v.begin(), v.end(), rng);
    for (int i=0;i<V;++i)
        grid[v[i].f][v[i].s]='V';
    for (int i=V;i<V+Z;++i)
        grid[v[i].f][v[i].s]='Z';
    for (int i=V+Z;i<V+Z+G;++i)
        grid[v[i].f][v[i].s]='G';
    int score=calc(),newScore;
    double t = 50;
    while (score)
    {
        t *= 0.999;
        a = uniform_int_distribution<int>(0,V+G+Z-1)(rng);
        b = uniform_int_distribution<int>(0,V+G+Z-1)(rng);
        while (grid[v[a].f][v[a].s]==grid[v[b].f][v[b].s])
        {
            a = uniform_int_distribution<int>(0,V+G+Z-1)(rng);
            b = uniform_int_distribution<int>(0,V+G+Z-1)(rng);
        }
        swap(grid[v[a].f][v[a].s],grid[v[b].f][v[b].s]);
        newScore=calc();
        if (newScore<=score||rnd()<exp((score-newScore)/t))
            score=newScore;
        else
            swap(grid[v[a].f][v[a].s],grid[v[b].f][v[b].s]);
    }
    for (int i=0;i<n;++i)
        cout<<grid[i]<<"\n";
    return 0;
}

//7 max bound