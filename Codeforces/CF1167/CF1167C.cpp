#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int g=1;
map<int,int> groupNumber;
vector<int> v;
map<int,vector<int>> edges;

int dfs(int x, int t)
{
    //cout<<x<<" entered\n";
    ++t;
    groupNumber[x]=g;
    //cout<<x<<" "<<l<<"\n";
    for (int j=0;j<sz(edges[x]);++j)
    {
        //cout<<"!!!"<<x<<" "<<j<<"\n";
        //cout<<"edge no: "<<edges[x][i]<<"\n";
        if (!groupNumber[edges[x][j]])
        {
            t=dfs(edges[x][j],t);
        }
    }
    //cout<<x<<" done\n";
    return t;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    v.push_back(69);
    int n,m,k,e,f,curGroupCount;
    cin>>n>>m;
    for (int i=0;i<m;++i)
    {
        cin>>k;
        if (k)
        {
            cin>>e;
            for (int i=1;i<k;++i)
            {
                cin>>f;
                edges[e].push_back(f);
                edges[f].push_back(e);
                //cout<<e<<" "<<f<<"\n";
            }
        }
    }
    for (int i=0;i<n;++i)
    {
        if (!groupNumber[i+1])
        {
            curGroupCount=dfs(i+1,0);
            v.push_back(curGroupCount);
            ++g;
        }
        cout<<v[groupNumber[i+1]]<<" ";
    }
    return 0;
}