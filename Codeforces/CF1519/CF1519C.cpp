#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5+1;
vector<int> dv[N], a[N];
int u[N];
ll ans[N];

void solve()
{
    int n,x;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        a[i].clear();
        ans[i]=0;
    }
    for (int i=0;i<n;++i)
        cin>>u[i];
    for (int i=0;i<n;++i)
    {
        cin>>x;
        a[u[i]].push_back(x);
    }
    for (int i=1;i<=n;++i)
    {
        sort(a[i].rbegin(), a[i].rend());
        vector<ll> p(sz(a[i])+1);
        p[0]=0;
        for (int j=1;j<=sz(a[i]);++j)
        {
            p[j]=p[j-1]+a[i][j-1];
            for (int k : dv[j])
                ans[k]+=p[j]-p[j-k];
        }
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    for (int i=1;i<N;++i)
        for (int j=i;j<N;j+=i)
            dv[j].push_back(i);
    while (t--)
        solve();
    return 0;
}