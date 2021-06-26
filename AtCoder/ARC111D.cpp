#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 105;
int reach[mn];
bitset<mn*mn> dir;
bitset<mn> done, edgeDir[mn];
vector<int> dfsEdge[mn];

void dfs(int c, int p)
{
    cout<<c<<"!\n";
    done[c]=1;
    for (int i : dfsEdge[c])
        if (i!=p)
        {
            if (done[i])
            {
                if (!edgeDir[i][c])
                {
                    cout<<c<<" "<<i<<"\n";
                    edgeDir[c][i]=1;
                }
            }
            else
            {
                cout<<c<<" "<<i<<"\n";
                edgeDir[c][i]=1;
                dfs(i,c);
            }
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    array<int,2> edges[m];
    for (int i=0;i<m;++i)
        cin>>edges[i][0]>>edges[i][1];
    for (int i=1;i<=n;++i)
    {
        cin>>reach[i];
        cout<<i<<": "<<reach[i]<<"\n";
    }
    for (int i=0;i<m;++i)
    {
        cout<<edges[i][0]<<" "<<edges[i][1]<<"!!\n";
        cout<<reach[edges[i][0]]<<" "<<reach[edges[i][1]]<<"\n";
        if (reach[edges[i][0]]>reach[edges[i][1]])
            dir[i]=0;
        else if (reach[edges[i][0]]<reach[edges[i][1]])
            dir[i]=1;
        else
        {
            dfsEdge[edges[i][0]].push_back(edges[i][1]);
            dfsEdge[edges[i][1]].push_back(edges[i][0]);
        }
    }
    for (int i=1;i<=n;++i)
        if (!done[i])
            dfs(i,0);
    for (int i=0;i<m;++i)
    {
        if (reach[edges[i][0]]==reach[edges[i][1]])
            if (edgeDir[edges[i][1]][edges[i][0]])
                dir[i]=1;
        if (dir[i])
            cout<<"<--\n";
        else
            cout<<"-->\n";
    }
    return 0;
}