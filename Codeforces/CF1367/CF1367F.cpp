#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,cur=1,x,ans=1;
    vector<pair<int,int>> v;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        v.push_back({x,i});
    }
    sort(v.begin(), v.end());
    for (int i=1;i<n;++i)
    {
        if (v[i-1].second<v[i].second)
            ++cur;
        else
            cur=1;
        ans=max(ans,cur);
    }
    cout<<n-ans<<"\n";
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