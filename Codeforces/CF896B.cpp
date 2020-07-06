#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int query(int start, int end, int div)
{
    if (end%div&&start%div)
        return end/div-start/div;
    if (start%div==0&&end%div==0)
        return end/div-start/div+1;
    if (start%div==0)
        return end/div-start/div+1;
    return end/div-start/div;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,k,l,r,m1,m2,g;
    ll ans=0,cur;
    cin>>n>>x>>k;
    map<int,int> m;
    vector<int> v;
    for (int i=0;i<n;++i)
    {
        cin>>g;
        if (!m[g])
            v.push_back(g);
        ++m[g];
    }
    vector<pair<int,int>> a={{0,0}};
    for (auto i : v)
        a.push_back({i,m[i]});
    sort(a.begin(), a.end());
    n=sz(a);
    int prefix[n];
    for (int i=1;i<n;++i)
        prefix[i]=prefix[i-1]+a[i].second;
    for (int i=1;i<n;++i)
    {
        if (query(a[i].first,a[i].first,x)>k||query(a[i].first,a[n-1].first,x)<k)
            continue;
        l=i;
        r=n-1;
        while (l<r)
        {
            m1=l+(r-l)/2;
            g=query(a[i].first,a[m1].first,x);
            if (g<k)
                l=m1+1;
            else if (query(a[i].first,a[m1].first,x)==k)
                r=m1;
            else
                r=m1-1;
        }
        m1=l;
        l=i;
        r=n-1;
        while (l<r)
        {
            m2=l+(r-l)/2+1;
            g=query(a[i].first,a[m2].first,x);
            if (g<k)
                l=m2+1;
            else if (query(a[i].first,a[m2].first,x)==k)
                l=m2;
            else
                r=m2-1;
        }
        m2=l;
        if (i<=m1&&m1<n&&i<=m2&&m2<n&&query(a[i].first,a[m1].first,x)==k&&query(a[i].first,a[m2].first,x)==k)
        {
            cur=(prefix[m2]-prefix[m1-1]);
            cur*=a[m1].second;
            ans+=cur;
        }
    }
    cout<<ans;
    return 0;
}