#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,maxDone=0,k,d;
    ll ans=0,c;
    cin>>n;
    int a[n];
    int t[n];
    int f[n];
    set<pair<int,int>> s;
    map<int,vector<pair<int,int>>> m;
    vector<int> v;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for (int i=0;i<n;++i)
    {
        cin>>t[i];
        v.push_back(a[i]);
        m[a[i]].push_back({t[i],i});
    }
    d=sz(v);
    sort(v.begin(), v.end());
    for (int x=0;x<d;++x)
    {
        if (v[x]>maxDone)
        {
            maxDone=v[x];
            k=sz(m[v[x]]);
            for (int i=0;i<k;++i)
            {
                s.insert(m[v[x]][i]);
            }
            m[v[x]].clear();
            for (int cur=v[x];sz(s);++cur)
            {
                k=sz(m[cur]);
                for (int i=0;i<k;++i)
                {
                    s.insert(m[cur][i]);
                }
                m[v[x]].clear();
                maxDone=cur;
                //cout<<cur<<": "<<(*(s.rbegin())).second<<"\n";
                f[(*(s.rbegin())).second]=cur;
                s.erase(*(s.rbegin()));
            }
        }
    }
    for (int i=0;i<n;++i)
    {
        c=f[i]-a[i];
        ans+=(c*t[i]);
    }
    cout<<ans;
    return 0;
}