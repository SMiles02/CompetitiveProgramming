#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<array<int,2>> v(m);
    vector<int> ans(m),w(m);
    for (int i=0;i<m;++i)
        v[i][0]=INF,v[i][1]=i;
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<m;++j)
            cin>>w[j];
        sort(v.begin(), v.end());
        sort(w.rbegin(), w.rend());
        for (int j=0;j<m;++j)
            v[j][0]=min(v[j][0],w[j]),ans[v[j][1]]=w[j];
        for (int j=0;j<m;++j)
            cout<<ans[j]<<" ";
        cout<<"\n";
    }
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