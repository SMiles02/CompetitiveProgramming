#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,l,r,mid;
    cin>>n>>m>>k;
    if (n+m-2<k)
    {
        cout<<-1;
        return 0;
    }
    vector<array<int,2>> v,w;
    for (int i=1;i<=n;++i)
    {
        v.push_back({n/i-1,n/(n/i)});
        i=n/(n/i);
    }
    for (int i=1;i<=m;++i)
    {
        w.push_back({m/i-1,m/(m/i)});
        i=m/(m/i);
    }
    long long ans=1;
    for (auto i : v)
    {
        if (i[0]+m-1<k)
            continue;
        l=0;r=w.size()-1;
        while (l<r)
        {
            mid=l+(r-l)/2+1;
            if (i[0]+w[mid][0]<k)
                r=mid-1;
            else
                l=mid;
        }
        ans=max(ans,1LL*i[1]*w[l][1]);
    }
    cout<<ans;
    return 0;
}