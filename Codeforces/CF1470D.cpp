#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 3e5+69;
int t,col[mn];
vector<int> edges[mn];
bitset<mn> done;

void dfs(int c)
{
    ++t;
    done[c]=1;
    for (int i : edges[c])
        if (!done[i])
            dfs(i);
}

void colour(int c, int x)
{
    col[c]=x;
    done[c]=1;
    queue<int> q;
    q.push(c);
    int y;
    while (!q.empty())
    {
        y=q.front();
        q.pop();
        for (int i : edges[y])
        {
            if (!done[i])
            {
                done[i]=1;
                q.push(i);
                col[i]=col[y]^1;
            }
            else if (col[i]&&col[y])
                col[i]=0;
        }
    }
}

void printAns(int n)
{
    int c=0;
    cout<<"YES\n";
    for (int i=1;i<=n;++i)
        c+=col[i];
    cout<<c<<"\n";
    for (int i=1;i<=n;++i)
        if (col[i])
            cout<<i<<" ";
    cout<<"\n";
}

void solve()
{
    int n,m,x,y;
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        edges[i].clear();
        done[i]=0;
    }
    while (m--)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    t=0;
    dfs(1);
    if (t!=n)
    {
        cout<<"NO\n";
        return;
    }
    for (int i=1;i<=n;++i)
        done[i]=0;
    colour(1,1);
    printAns(n);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}