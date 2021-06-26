#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 1e5+7;
int edges[mn],scores[mn];

void solve()
{
    int n,x,y;
    cin>>n;
    ll z=0;
    vector<ll> ans;
    vector<int> toRemove;
    for (int i=1;i<=n;++i)
    {
        cin>>scores[i];
        edges[i]=0;
    }
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        ++edges[x];
        ++edges[y];
        z+=scores[x]+scores[y];
    }
    ans.push_back(z);
    for (int i=1;i<=n;++i)
        for (int j=1;j<edges[i];++j)
            toRemove.push_back(scores[i]);
    sort(toRemove.begin(), toRemove.end());
    for (int i : toRemove)
        ans.push_back(ans.back()-i);
    for (int i=n-2;i>=0;--i)
        cout<<ans[i]<<" ";
    cout<<"\n";
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