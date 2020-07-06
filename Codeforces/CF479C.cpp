#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b,cur;
    cin>>n;
    vector<pair<int,int>> v;
    for (int i=0;i<n;++i)
    {
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    cur=v[0].second;
    for (int i=1;i<n;++i)
    {
        if (v[i].second<cur)
        {
            cur=v[i].first;
        }
        else
        {
            cur=v[i].second;
        }
    }
    cout<<cur;
    return 0;
}