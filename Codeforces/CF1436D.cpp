#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int maxn=2e5+1;
ll a[maxn],b[maxn],ans;
vector<int> edges[maxn];

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

void dfs(int c)
{
    if (edges[c].empty())
        ++b[c];
    else
        for (int i : edges[c])
        {
            dfs(i);
            a[c]+=a[i];
            b[c]+=b[i];
        }
    ans=max(ans,(a[c]+b[c]-1)/b[c]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n;
    for (int i=2;i<=n;++i)
    {
        cin>>k;
        edges[k].push_back(i);
    }
    for (int i=1;i<=n;++i)
        cin>>a[i];
    dfs(1);
    cout<<ans;
    return 0;
}