#include <bits/stdc++.h>
using namespace std;

const int N = 4e5+1;
int n, k, a[N];

bool ok(int x)
{
    int cur=0;
    for (int i=x;i<k;++i)
    {
        if (cur>=a[i])
            return 0;
        cur+=n-a[i];
    }
    return 1;
}

void solve()
{
    int l,r,m;
    cin>>n>>k;
    for (int i=0;i<k;++i)
        cin>>a[i];
    sort(a,a+k);
    if (!ok(k-1))
    {
        cout<<"0\n";
        return;
    }
    l=0;r=k-1;
    while (l<r)
    {
        m=l+(r-l)/2;
        if (ok(m))
            r=m;
        else
            l=m+1;
    }
    cout<<k-l<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}