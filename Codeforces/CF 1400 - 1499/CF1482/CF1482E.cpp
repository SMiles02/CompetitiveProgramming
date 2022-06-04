#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct segtree
{
    const ll MN_VAL = -1e18;
    int n;
    vector<ll> v;
    segtree(int n) : n(n), v(n*4+20, MN_VAL) {}
    void update(int i, int l, int r, int j, ll x)
    {
        if (j<l||r<j)
            return;
        if (l==r)
        {
            v[i]=x;
            return;
        }
        int m=l+(r-l)/2;
        if (j<=m)
            update(i*2+1,l,m,j,x);
        else
            update(i*2+2,m+1,r,j,x);
        v[i]=max(v[i*2+1],v[i*2+2]);
    }
    void update(int i, ll x)
    {
        update(0,0,n,i,x);
    }
    ll query(int i, int l, int r, int qL, int qR)
    {
        if (r<qL||qR<l)
            return MN_VAL;
        if (qL<=l&&r<=qR)
            return v[i];
        int m=l+(r-l)/2;
        return max(query(i*2+1,l,m,qL,qR),query(i*2+2,m+1,r,qL,qR));
    }
    ll query(int l, int r)
    {
        if (l>r)
            return MN_VAL;
        return query(0,0,n,l,r);
    }
};

const int N = 3e5+7;
ll dp[N];
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int h[n+1], b[n+1];
    stack<int> s;
    s.push(0);
    h[0]=0;
    segtree seg(n);
    seg.update(0,0);
    dp[0]=-1e18;
    for (int i=1;i<=n;++i)
        cin>>h[i];
    for (int i=1;i<=n;++i)
    {
        cin>>b[i];
        while (h[s.top()]>=h[i])
            s.pop();
        dp[i]=max(dp[s.top()],seg.query(s.top(),i-1)+b[i]);
        seg.update(i,dp[i]);
        s.push(i);
    }
    cout<<dp[n];
    return 0;
}