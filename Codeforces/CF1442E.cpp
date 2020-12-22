#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int maxn = 2e5+1;
vector<int> edges[maxn];
bitset<maxn> done;

void dfs(int c)
{
    done[c]=1;
    for (int i : edges[c])
        if (!done[i])
            dfs(i);
}

void solve()
{
    int n,x,y,b=0,w=0;
    cin>>n;
    int a[n+1];
    for (int i=1;i<=n;++i)
    {
        edges[i].clear();
        done[i]=0;
    }
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        if (a[x]==a[y])
            if (a[x])
            {
                edges[x].push_back(y);
                edges[y].push_back(x);
            }
    }
    for (int i=1;i<=n;++i)
        if (a[i]&&!done[i])
        {
            if (a[i]==1)
                ++b;
            else
                ++w;
            dfs(i);
        }
    if (b==0||w==0)
        cout<<"1\n";
    else
        cout<<min(b,w)+1<<"\n";
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