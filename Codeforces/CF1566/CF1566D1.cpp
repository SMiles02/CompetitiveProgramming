#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n,rtn;
    vector<int> bit;
    BIT(int n) : n(n), bit(n+1,0) {}
    void update(int x, int d) {
        for (int i=x;i<=n;i+=i&-i)
            bit[i]+=d;
    }
    int query(int x) {
        rtn=0;
        for (int i=x;i;i-=i&-i)
            rtn+=bit[i];
        return rtn;
    }
    int query(int x, int y) {
        return query(y) - query(x-1);
    }
};

void solve()
{
    int n,m,ans=0;
    cin>>n>>m;
    array<int,2> a[m];
    int ord[m];
    BIT bit(m+1);
    for (int i=0;i<m;++i)
    {
        cin>>a[i][0];
        a[i][1]=-i;
    }
    sort(a,a+m);
    for (int i=0;i<m;++i)
        ord[-a[i][1]]=i+1;
    for (int i=0;i<m;++i)
    {
        ans+=bit.query(ord[i]);
        bit.update(ord[i],1);
    }
    cout<<ans<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}