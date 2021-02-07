#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 1e5+1;
vector<int> v[mn],w[mn];

void solve()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[n],c[m],ans[m],done=-1;
    for (int i=1;i<=n;++i)
    {
        v[i].clear();
        w[i].clear();
    }
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
        cin>>b[i];
    for (int i=0;i<n;++i)
    {
        if (a[i]==b[i])
            w[a[i]].push_back(i);
        else
            v[b[i]].push_back(i);
    }
    for (int i=0;i<m;++i)
        cin>>c[i];
    for (int i=m-1;i+1;--i)
    {
        if (!v[c[i]].empty())
        {
            ans[i]=v[c[i]].back();
            done=v[c[i]].back();
            v[c[i]].pop_back();
        }
        else if (!w[c[i]].empty())
        {
            ans[i]=w[c[i]].back();
            done=w[c[i]].back();
            w[c[i]].pop_back();
        }
        else if (done>-1)
            ans[i]=done;
        else
        {
            cout<<"NO\n";
            return;
        }
    }
    for (int i=1;i<=n;++i)
        if (!v[i].empty())
        {
            cout<<"NO\n";
            return;
        }
    cout<<"YES\n";
    for (int i=0;i<m;++i)
        cout<<ans[i]+1<<" ";
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