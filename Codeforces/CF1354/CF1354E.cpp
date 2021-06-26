#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int twos,tot,g;
bool flag=0;
int done[5001];
map<int,vector<int>> edges;
bool dp[5001][5001][2];
int groupSize[5001][2];
int group[5001];
bool cor[5001];

bool max(bool a, bool b)
{
    if (a||b)
        return 1;
    return 0;
}

void dfs(int cur, int colour)
{
    ++tot;
    group[cur]=g;
    done[cur]=colour;
    if (colour==1)
        ++twos;
    int k=sz(edges[cur]);
    for (int i=0;i<k;++i)
    {
        if (done[edges[cur][i]])
        {
            if (colour+done[edges[cur][i]]!=3)
                flag=1;
        }
        else
            dfs(edges[cur][i],3-colour);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,c=0,x,y,z,u,v;
    cin>>n>>m;
    cin>>x>>y>>z;
    while (m--)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dp[0][0][0]=1;
    dp[0][0][1]=1;
    for (int i=1;i<=n;++i)
        if (!done[i])
        {
            ++c;
            twos=0;tot=0;
            g=c;
            dfs(i,1);
            groupSize[c][0]=twos;
            groupSize[c][1]=tot-twos;
            for (int j=5000;j-twos>=0;--j)
                if (dp[c-1][j-twos][0]||dp[c-1][j-twos][1])
                    dp[c][j][0]=1;
            for (int j=5000;j-(tot-twos)>=0;--j)
                dp[c][j][1]=max(dp[c-1][j-(tot-twos)][0],dp[c-1][j-(tot-twos)][1]);
        }
    if (flag||!(dp[c][y][0]||dp[c][y][1]))
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    v=y;
    for (int i=c;i;--i)
    {
        if (dp[i][v][0])
        {
            cor[i]=1;
            v-=groupSize[i][0];
        }
        else
        {
            cor[i]=0;
            v-=groupSize[i][1];
        }
    }
    for (int i=1;i<=n;++i)
    {
        if (cor[group[i]])
        {
            if (done[i]==1)
                cout<<2;
            else if (x)
            {
                cout<<1;
                --x;
            }
            else
                cout<<3;
        }
        else
        {
            if (done[i]==1)
            {
                if (x)
                {
                    cout<<1;
                    --x;
                }
                else
                    cout<<3;
            }
            else
                cout<<2;
        }
    }
    return 0;
}