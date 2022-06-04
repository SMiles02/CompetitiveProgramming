#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

void solve()
{
    int n,k;
    cin>>n;
    vector<pii> v;
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        v.push_back({k,i});
    }
    sort(v.begin(), v.end());
    if (v[0].f==v[n-1].f)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for (int i=1;i<n;++i)
    {
        if (v[i].f==v[0].f)
            cout<<v[i].s<<" "<<v[n-1].s<<"\n";
        else
            cout<<v[i].s<<" "<<v[0].s<<"\n";
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