#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans,x,h;
    cin>>n;
    vector<pair<int,int>> v;
    for (int i=0;i<n;++i)
    {
        cin>>x>>h;
        v.push_back({x,h});
    }
    sort(v.begin(), v.end());
    ans=min(n,2);
    for (int i=1;i<n-1;++i)
    {
        if (v[i-1].first<v[i].first-v[i].second)
        {
            ++ans;
        }
        else if (v[i].first+v[i].second<v[i+1].first)
        {
            ++ans;
            v[i].first+=v[i].second;
        }
    }
    cout<<ans;
    return 0;
}