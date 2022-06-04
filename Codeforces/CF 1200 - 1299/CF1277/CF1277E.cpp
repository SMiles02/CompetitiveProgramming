#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll ans,multi;
int n,m,a,b,x,y,k;
map<int,vector<int>> edges;
map<int,int> done1;
map<int,int> done2;

void dfs1(int cur)
{
    done1[cur]=1;
    k=sz(edges[cur]);
    //cout<<cur<<" has "<<k<<" edges\n";
    for (int j=0;j<sz(edges[cur]);++j)
    {
        //cout<<"cur = "<<cur<<", j = "<<j<<"\n";
        //cout<<"edge "<<cur<<" "<<edges[cur][j]<<"\n";
        if (!done1[edges[cur][j]])
        {
            if (edges[cur][j]!=b)
            {
                dfs1(edges[cur][j]);
            }
        }
    }
    return;
}

void dfs2(int cur)
{
    done2[cur]=1;
    k=sz(edges[cur]);
    for (int i=0;i<k;++i)
    {
        if (!done2[edges[cur][i]])
        {
            if (edges[cur][i]!=a)
            {
                dfs2(edges[cur][i]);
            }
        }
    }
    return;
}

void solve()
{
    ans=0;multi=0;
    cin>>n>>m>>a>>b;
    while (m--)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs1(a);
    dfs2(b);
    x=-1;
    y=-1;
    //cout<<"fourcheck = "<<done1[4]<<" "<<done2[4]<<"\n";
    for (int i=1;i<=n;++i)
    {
        if (done1[i]&&!done2[i])
        {
            ++x;
            //cout<<"1 "<<i<<"\n";
        }
        if (done2[i]&&!done1[i])
        {
            ++y;
            //cout<<"2 "<<i<<"\n";
        }
    }
    ans=x;
    ans*=y;
    cout<<ans<<"\n";
    edges.clear();
    done1.clear();
    done2.clear();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}