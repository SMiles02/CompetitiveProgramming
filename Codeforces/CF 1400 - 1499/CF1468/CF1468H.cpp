#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 2e5+1;
bitset<mn> gg;

void solve()
{
    int n,k,m,l,r,mid,x,y;
    cin>>n>>k>>m;
    int good[m];
    set<int> s;
    for (int i=1;i<=n;++i)
        gg[i]=1;
    for (int i=0;i<m;++i)
    {
        cin>>good[i];
        gg[good[i]]=0;
    }
    if ((n-m)%(k-1))
    {
        cout<<"NO\n";
        return;
    }
    for (int i=1;i<=n;++i)
        if (gg[i])
            s.insert(i);
    for (int i=0;i<k/2;++i)
    {
        x=*(s.begin());
        s.erase(s.begin());
    }
    for (int i=0;i<k/2;++i)
    {
        y=*(--s.end());
        s.erase(--s.end());
    }
    if (good[m-1]<x)
    {
        cout<<"NO\n";
        return;
    }
    l=0;r=m-1;
    while (l<r)
    {
        mid=l+(r-l)/2;
        if (good[mid]<x)
            l=mid+1;
        else
            r=mid;
    }
    if (!(x<good[l]&&good[l]<y))
            cout<<"NO\n";
    else
        cout<<"YES\n";
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