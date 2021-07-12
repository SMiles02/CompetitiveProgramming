#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
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