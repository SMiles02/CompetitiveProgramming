#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MAXN=1e5+10;
int n,mod=1e9+7;
vector<ll> ans;
vector<int> edges[MAXN];
ll subTree[MAXN];

void dfs(int c, int p)
{
    subTree[c]=1;
    for (int i : edges[c])
        if (i!=p)
        {
            //cout<<"dfs("<<i<<","<<c<<")\n";
            dfs(i,c);
            ans.push_back(subTree[i]*(n-subTree[i]));
            subTree[c]+=subTree[i];
        }
    //cout<<c<<": "<<subTree[c]<<"\n";
}

ll mult(ll a, ll b)
{
    return ((a%mod)*(b%mod))%mod;
}

ll add(ll a, ll b)
{
    return ((a%mod)+(b%mod))%mod;
}

void solve()
{
    int u,v,m,k;
    cin>>n;
    ans.clear();
    for (int i=1;i<=n;++i)
        edges[i].clear();
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cin>>m;
    vector<ll> p;
    for (int i=0;i<m;++i)
    {
        cin>>k;
        p.push_back(k);
    }
    sort(p.begin(), p.end());
    while (sz(p)>n-1)
    {
        k=p.back();
        p.pop_back();
        p.back()=mult(p.back(),k);
    }
    while (sz(p)<n-1)
        p.push_back(1);
    dfs(1,0);
    sort(p.begin(), p.end());
    sort(ans.begin(), ans.end());
    ll tot=0;
    for (int i=0;i<n-1;++i)
        tot=add(mult(ans[i],p[i]),tot);
    cout<<tot<<"\n";
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