#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mod = 998244353;
ll f[51];
vector<int> edges[51];
bitset<51> done;
int d;

void dfs(int c)
{
    ++d;
    done[c]=1;
    for (int i : edges[c])
        if (!done[i])
            dfs(i);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    f[0]=1;
    for (int i=1;i<51;++i)
        f[i]=(f[i-1]*i)%mod;
    int n,x;
    cin>>n>>x;
    int a[n][n];
    ll ans=1;
    bool ok;
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            cin>>a[i][j];
    for (int i=0;i<n;++i)
        for (int j=0;j<i;++j)
        {
            ok=1;
            for (int k=0;k<n;++k)
                if (a[i][k]+a[j][k]>x)
                    ok=0;
            if (ok)
            {
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    for (int i=0;i<n;++i)
        if (!done[i])
        {
            d=0;
            dfs(i);
            ans*=f[d];
            ans%=mod;
        }
    done.reset();
    for (int i=0;i<n;++i)
        edges[i].clear();
    for (int i=0;i<n;++i)
        for (int j=0;j<i;++j)
        {
            ok=1;
            for (int k=0;k<n;++k)
                if (a[k][i]+a[k][j]>x)
                    ok=0;
            if (ok)
            {
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    for (int i=0;i<n;++i)
        if (!done[i])
        {
            d=0;
            dfs(i);
            ans*=f[d];
            ans%=mod;
        }
    cout<<ans;
    return 0;
}