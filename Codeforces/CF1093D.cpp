#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll o,t,ans;
bool f;
int mod=998244353;
vector<int> edges[300001];
int done[300001];

ll binpow(ll a, ll b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    res%=mod;
    if (b % 2)
    {
        return (res * a)%mod;
    }
    return res;
}

void dfs(int cur, int k)
{
    done[cur]=k;
    if (k==1)
        ++o;
    else
        ++t;
    for (auto x : edges[cur])
    {
        if (done[x])
        {
            if (done[x]==k)
                f=1;
        }
        else
            dfs(x,3-k);
    }
}

void solve()
{
    int n,m,u,v;
    cin>>n>>m;
    ans=1;f=0;
    for (int i=1;i<=n;++i)
    {
        edges[i].clear();
        done[i]=0;
    }
    for (int i=0;i<m;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int i=1;i<=n;++i)
        if (!done[i])
        {
            o=0;t=0;
            dfs(i,1);
            ans*=((binpow(2,o)+binpow(2,t))%mod);
            ans%=mod;
        }
    if (f)
        cout<<"0\n";
    else

    cout<<ans<<"\n";
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