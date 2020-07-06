#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,x,y,curX=0,curY=0;
    cin>>n;
    vector<pair<int,int>> v;
    for (int i=0;i<n;++i)
    {
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(), v.end());
    for (int i=1;i<n;++i)
    {
        if (!(v[i].first>=v[i-1].first&&v[i].second>=v[i-1].second))
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    for (int i=0;i<n;++i)
    {
        while (curX<v[i].first)
        {
            cout<<"R";
            ++curX;
        }
        while (curY<v[i].second)
        {
            cout<<"U";
            ++curY;
        }
    }
    cout<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}