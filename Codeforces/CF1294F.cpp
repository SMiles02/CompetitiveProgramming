#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<int,vector<int>> edges;
map<int,int> parent;
map<int,vector<int>> children;
int maxiHeight;
int indiceOfMaxHeight;
int root;
vector<pair<int,int>> greatestDistances;
int curMax,curIndice,origin;

void finderDFS(int cur, int height)
{
    if (height>curMax)
    {
        curMax=height;
        curIndice=cur;
    }
    int k=sz(children[cur]);
    for (int i=0;i<k;++i)
    {
        if (children[cur][i]!=origin)
        {
            finderDFS(children[cur][i],height+1);
        }
    }
    return;
}

void finder(int cur)
{
    origin=cur;
    if (parent[cur]!=root)
    {
        finderDFS(parent[cur],0);
        finder(parent[cur]);
    }
    return;
}

void dfs(int cur,int height)
{
    if (height>maxiHeight)
    {
        maxiHeight=height;
        indiceOfMaxHeight=cur;
    }
    int k=sz(edges[cur]);
    for (int i=0;i<k;++i)
    {
        if (edges[cur][i]!=parent[cur])
        {
            children[cur].push_back(edges[cur][i]);
            dfs(edges[cur][i],height+1);
        }
    }
    return;
}

void rootDfs()
{
    int k=sz(edges[root]);
    cout<<"test";
    return;
    for (int i=0;i<k;++i)
    {
        maxiHeight=0;
        dfs(edges[root][i],1);
        greatestDistances.push_back({maxiHeight,indiceOfMaxHeight});
    }
    sort(greatestDistances.begin(), greatestDistances.end());
    int a=greatestDistances.back().second,ans=greatestDistances.back().first,b;
    greatestDistances.pop_back();
    b=greatestDistances.back().second;
    ans+=greatestDistances.back().first;
    greatestDistances.pop_back();
    int oneMax,oneCur;
    curMax=0;curIndice=0;
    finder(a);
    oneMax=curMax;oneCur=curIndice;
    curMax=0;curIndice=0;
    finder(b);
    if (sz(greatestDistances))
    {
        if (greatestDistances.back().first==max(greatestDistances.back().first,max(curMax,oneMax)))
        {
            cout<<ans+greatestDistances.back().first<<"\n";
            cout<<a<<" "<<b<<" "<<greatestDistances.back().second;
        }
        else if (curMax>oneMax)
        {
            cout<<ans+curMax<<"\n";
            cout<<a<<" "<<b<<" "<<curIndice;
        }
        else
        {
            cout<<ans+oneMax<<"\n";
            cout<<a<<" "<<b<<" "<<oneCur;
        }
        return;
    }
    if (curMax>oneMax)
    {
        cout<<ans+curMax<<"\n";
        cout<<a<<" "<<b<<" "<<curIndice;
    }
    else
    {
        cout<<ans+oneMax<<"\n";
        cout<<a<<" "<<b<<" "<<oneCur;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    if (n==3)
    {
        cout<<"2\n1 2 3";
        return 0;
    }
    for (int i=1;i<=n;++i)
    {
        if (sz(edges[i])>1)
        {
            root=i;
            rootDfs();
            return 0;
        }
    }
    return 0;
}