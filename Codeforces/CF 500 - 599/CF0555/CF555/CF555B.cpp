#include <bits/stdc++.h>
#define ll long long
using namespace std;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    int ans[n];
    ll k;
    vector<array<ll,3>> v(n-1);
    vector<array<ll,2>> a(n);
    set<array<ll,2>> s;
    for (int i=0;i<n;++i)
        for (int j=0;j<2;++j)
            cin>>a[i][j];
    sort(a.begin(), a.end());
    for (int i=0;i+1<n;++i)
        v[i]={a[i+1][1]-a[i][0],a[i+1][0]-a[i][1],i};
    for (int i=0;i<m;++i)
    {
        cin>>k;
        s.insert({k,i+1});
    }
    sort(v.begin(), v.end());
    for (auto i : v)
    {
        if (s.lower_bound({i[1],0})==s.end()||i[0]<(*s.lower_bound({i[1],0}))[0])
        {
            cout<<"No";
            return 0;
        }
        ans[i[2]]=(*s.lower_bound({i[1],0}))[1];
        s.erase(s.lower_bound({i[1],0}));
    }
    cout<<"Yes\n";
    for (int i=0;i+1<n;++i)
        cout<<ans[i]<<" ";
    return 0;
}