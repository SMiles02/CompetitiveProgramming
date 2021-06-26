#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<int,vector<int>> edges;
int parent[100001];
int onlyEdge[100001];
vector<pair<int,int>> v;
int d[100001];
int x,y;

void buildTree(int cur, int p, int colour)
{
    d[cur]=1;
    parent[cur]=p;
    int k=sz(edges[cur]);
    if (k==1)
    {
        v.push_back({cur,0});
        onlyEdge[cur]=edges[cur][0];
        if (colour)
        {
            y=1;
        }
        else
        {
            x=1;
        }
    }
    for (int i=0;i<k;++i)
    {
        if (!d[edges[cur][i]]) buildTree(edges[cur][i],cur,1-colour);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b,k,maxi;
    vector<pair<int,int>> w;
    map<pair<int,int>,int> parityDone;
    map<int,int> done;
    cin>>n;
    maxi=n-1;
    for (int i=1;i<n;++i)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    buildTree(1,0,0);
    w=v;
    k=sz(v);
    for (int i=0;i<k;++i)
    {
        //cout<<"cur="<<v[i].first<<"\n";
        if (done[onlyEdge[v[i].first]])
        {
            //cout<<"alreadyDone "<<v[i].first<<"\n";
            --maxi;
        }
        done[onlyEdge[v[i].first]]=1;
    }
    done.clear();
    if (x&&y)
    {
        cout<<3;
    }
    else
    {
        cout<<1;
    }
    cout<<" "<<maxi;
    return 0;
}