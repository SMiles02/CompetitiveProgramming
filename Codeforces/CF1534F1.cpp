#include <bits/stdc++.h>
using namespace std;

const int N = 4e5+7;
int scc[N], inc[N];
vector<int> e1[N], e2[N], w[N];
vector<bool> d1, d2;
stack<int> pile;
string s[N];

void addEdge(int x, int y)
{
    e1[x].push_back(y);
    e2[y].push_back(x);
}

void dfs1(int c)
{
    d1[c]=1;
    for (int i : e1[c])
        if (!d1[i])
            dfs1(i);
    pile.push(c);
}

void dfs2(int c, int g)
{
    d2[c]=1;
    scc[c]=g;
    for (int i : e2[c])
        if (!d2[i])
            dfs2(i,g);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,t=0,u=0,l,r,mid,ans=0;
    cin>>n>>m;
    for (int i=0;i<n;++i)
        cin>>s[i];
    vector<vector<int>> v(n,vector<int>(m,0));
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (s[i][j]=='#')
            {
                w[j].push_back(i);
                v[i][j]=++t;
            }
    for (int i=0;i<m;++i)
        for (int j=1;j<(int)w[i].size();++j)
        {
            addEdge(v[w[i][j-1]][i],v[w[i][j]][i]);
            if (w[i][j-1]+1==w[i][j])
                addEdge(v[w[i][j]][i],v[w[i][j-1]][i]);
        }
    for (int i=1;i<m;++i)
        if (!w[i-1].empty())
            for (int j : w[i])
            {
                if (w[i-1].back()<j)
                    break;
                l=0;
                r=w[i-1].size()-1;
                while (l<r)
                {
                    mid=l+(r-l)/2;
                    if (w[i-1][mid]<j)
                        l=mid+1;
                    else
                        r=mid;
                }
                addEdge(v[j][i],v[w[i-1][l]][i-1]);
            }
    for (int i=0;i+1<m;++i)
        if (!w[i+1].empty())
            for (int j : w[i])
            {
                if (w[i+1].back()<j)
                    break;
                l=0;
                r=w[i+1].size()-1;
                while (l<r)
                {
                    mid=l+(r-l)/2;
                    if (w[i+1][mid]<j)
                        l=mid+1;
                    else
                        r=mid;
                }
                addEdge(v[j][i],v[w[i+1][l]][i+1]);
            }
    d1.resize(t+1,0);
    d2.resize(t+1,0);
    for (int i=1;i<=t;++i)
        if (!d1[i])
            dfs1(i);
    while (!pile.empty())
    {
        if (!d2[pile.top()])
            dfs2(pile.top(),++u);
        pile.pop();
    }
    for (int i=1;i<=t;++i)
        for (int j : e1[i])
            if (scc[i]!=scc[j])
                ++inc[scc[j]];
    for (int i=1;i<=u;++i)
        ans+=(inc[i]==0);
    cout<<ans;
    return 0;
}