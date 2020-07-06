#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll n,x,y,ans,found,specialNum,sz1,totAns=1;
map<int,vector<int>> edges;
map<int,int> done;

void dfs(int cur)
{
    done[cur]=1;
    //cout<<"cur="<<cur<<", curDist="<<curDist<<"\n";
    if (cur==x)
    {
        found=1;
        return;
    }
    ++ans;
    ++totAns;
    for (int i=0;i<sz(edges[cur]);++i)
    {
        if (!done[edges[cur][i]])
        {
            dfs(edges[cur][i]);
        }
    }
    return;
}

void rootDFS()
{
    done[y]=1;
    for (int i=0;i<sz(edges[y]);++i)
    {
        if (!done[edges[y][i]])
        {
            ans=0;
            found=0;
            dfs(edges[y][i]);
            if (found)
            {
                sz1=ans;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b;
    cin>>n>>x>>y;
    for (int i=1;i<n;++i)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    rootDFS();
    //cout<<totAns<<" "<<sz1<<"\n";
    //cout<<n-totAns<<" "<<totAns-sz1<<"\n";
    cout<<((n)*(n-1))-((n-totAns)*(totAns-sz1));
    return 0;
}