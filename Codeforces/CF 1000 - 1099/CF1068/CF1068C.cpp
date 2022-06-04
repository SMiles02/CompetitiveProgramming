#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<int> edges[101];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,u,v,cur=0;
    cin>>n>>m;
    map<pair<int,int>,int> d;
    while (m--)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int i=1;i<=n;++i)
    {
        cout<<sz(edges[i])+1<<"\n";
        for (int j : edges[i])
        {
            if (i<j)
            {
                ++cur;
                cout<<i<<" "<<cur<<"\n";
                d[{j,i}]=cur;
            }
            else
                cout<<i<<" "<<d[{i,j}]<<"\n";
        }
        cout<<i<<" "<<5000-i<<"\n";
    }
    return 0;
}