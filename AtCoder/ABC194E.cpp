#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

struct BIT {
    int n,rtn;
    vector<int> bit;
    BIT(int n) : n(n), bit(n+1) {}
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
    int pQuery(int i) {
        return query(i) - query(i-1);
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,ans;
    cin>>n>>m;
    int a[n];
    BIT cur(n+4);
    multiset<int> s;
    for (int i=0;i<n+4;++i)
        s.insert(i);
    for (int i=0;i<m;++i)
    {
        cin>>a[i];
        cur.update(a[i]+1,1);
        if (s.count(a[i]))
            s.erase(s.find(a[i]));
    }
    ans=*(s.begin());
    for (int i=m;i<n;++i)
    {
        if (cur.pQuery(a[i-m]+1)==1)
            s.insert(a[i-m]);
        cur.update(a[i-m]+1,-1);
        cin>>a[i];
        cur.update(a[i]+1,1);
        if (s.count(a[i]))
            s.erase(s.find(a[i]));
        ans=min(ans,*(s.begin()));
    }
    cout<<ans;
    return 0;
}