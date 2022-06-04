#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int p[100001];
ll h[100001];
vector<int> edges[100001];
int passThrough[100001];
int parent[100001];
bool b;

void buildTree(int c, int pp)
{
    passThrough[c]=p[c];
    int x=0,d=0;
    for (int i : edges[c])
        if (i!=pp)
        {
            buildTree(i,c);
            passThrough[c]+=passThrough[i];
            parent[i]=c;
            x+=h[i];
            ++d;
        }
    if (p[c])
    {
        if (!(x-p[c]<=h[c]&&h[c]<=passThrough[c]))
            b=0;
    }
    else if ((!(x<=h[c]&&h[c]<=passThrough[c]&&abs(h[c]-x)%2==0)))
        b=0;
    if ((passThrough[c]+h[c])%2)
        b=0;
    else if ((passThrough[c]+h[c])/2>passThrough[c])
        b=0;
    return;
}

void solve()
{
    int n,m,u,v;
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        cin>>p[i];
        //cout<<"p["<<i<<"] = "<<p[i]<<"\n";
    }
    for (int i=1;i<=n;++i)
    {
        cin>>h[i];
        //cout<<"h["<<i<<"] = "<<h[i]<<"\n";
        edges[i].clear();
    }
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
        //cout<<u<<" "<<v<<"!!\n";
    }
    //return;
    b=1;
    buildTree(1,0);
    if (b)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}