#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x,l,r;
    cin>>n>>k;
    vector<pair<pair<int,int>,int>> v;
    int p[n+1];
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        p[x]=i;
    }
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        v.push_back({{min(i,p[x]),max(i,p[x])},x});
    }
    sort(v.rbegin(), v.rend());
    vector<int> w;
    vector<pair<pair<int,int>,vector<int>>> ans;
    while (sz(v))
    {
        l=v.back().first.first;
        r=v.back().first.second;
        w.push_back(v.back().second);
        v.pop_back();
        while (sz(v)&&v.back().first.first<=r)
        {
            r=max(v.back().first.second,r);
            w.push_back(v.back().second);
            v.pop_back();
        }
        ans.push_back({{l,r},w});
        w.clear();
    }
    if (sz(ans)<k)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    string alpha="abcdefghijklmnopqrstuvwxyz",s="";
    for (int i=0;i<n;++i)
        s+=' ';
    for (int i=0;i<k;++i)
        for (int j : ans[i].second)
            s[j-1]=alpha[i];
    for (int i=0;i<n;++i)
        if (s[i]==' ')
            s[i]=alpha[k-1];
    cout<<s;
    return 0;
}