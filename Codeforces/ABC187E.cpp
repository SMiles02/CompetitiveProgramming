#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 2e5+69;
int entry[mn];
ll scores[mn], toAdd[mn], tot;
vector<int> edges[mn];

void dfs(int c, int p)
{
    scores[c]=scores[p]+toAdd[c];
    entry[c]=entry[p]+1;
    for (int i : edges[c])
        if (i!=p)
            dfs(i,c);
}

void query(int x, int y, int z) 
{
    //increase all reachable from x
    //without going through y by z
    if (entry[x]>entry[y])
        toAdd[x]+=z;
    else
    {
        tot+=z;
        toAdd[y]-=z;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,x,y,z;
    cin>>n;
    int a[n][2];
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        a[i][0]=x;
        a[i][1]=y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs(1,0);
    cin>>q;
    while (q--)
    {
        cin>>x>>y>>z;
        if (x==1)
            query(a[y][0],a[y][1],z);
        else
            query(a[y][1],a[y][0],z);
    }
    dfs(1,0);
    for (int i=1;i<=n;++i)
        cout<<scores[i]+tot<<"\n";
    return 0;
}