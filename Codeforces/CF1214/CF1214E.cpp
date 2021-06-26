#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n;
    vector<pair<int,int>> v;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        v.push_back({k,2*i+1});
    }
    sort(v.rbegin(), v.rend());
    for (int i=0;i+1<n;++i)
        cout<<v[i].second<<" "<<v[i+1].second<<"\n";
    for (int i=0;i<n;++i)
    {
        if (v[i].first==n||i+v[i].first==sz(v))
        {
            cout<<v.back().second<<" "<<v[i].second+1<<"\n";
            v.push_back({n+1,v[i].second+1});
        }
        else
            cout<<v[i+v[i].first-1].second<<" "<<v[i].second+1<<"\n";
    }
    return 0;
}