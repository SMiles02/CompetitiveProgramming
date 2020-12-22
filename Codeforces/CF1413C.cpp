#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

int p[100001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a[6],ans=1e9,c=0;
    for (int i=0;i<6;++i)
        cin>>a[i];
    cin>>n;
    int b[n+1];
    vector<pii> v;
    for (int i=1;i<=n;++i)
    {
        cin>>b[i];
        for (int j=0;j<6;++j)
            v.push_back({b[i]-a[j],i});
    }
    sort(v.begin(), v.end());
    multiset<int> s;
    for (pii i : v)
    {
        if (p[i.s])
        {
            --c;
            s.erase(s.lower_bound(p[i.s]));
        }
        ++c;
        p[i.s]=i.f;
        s.insert(i.f);
        if (c==n)
            ans=min(ans,i.f-*s.begin());
    }
    cout<<ans;
    return 0;
}