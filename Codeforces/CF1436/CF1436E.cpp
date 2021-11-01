#include <bits/stdc++.h>
using namespace std;

template<class T> struct Segtree {
    // merge(ID,x) = x
    // range [0,n]
    const T ID = 1e9;
    int n;
    vector<T> v;
    Segtree(int n) : n(n), v(n*4+4, 0) {}
    T merge(T a, T b) { return min(a,b); }
    void update(int i, int l, int r, int j, T x) {
        if (j<l||r<j)
            return;
        if (l==r) {
            v[i]=x;
            return;
        }
        int m=l+(r-l)/2;
        if (j<=m)
            update(i*2+1,l,m,j,x);
        else
            update(i*2+2,m+1,r,j,x);
        v[i]=merge(v[i*2+1],v[i*2+2]);
    }
    void update(int i, T x) { update(0,0,n,i,x); }
    T query(int i, int l, int r, int qL, int qR) {
        if (r<qL||qR<l)
            return ID;
        if (qL<=l&&r<=qR)
            return v[i];
        int m=l+(r-l)/2;
        return merge(query(i*2+1,l,m,qL,qR),query(i*2+2,m+1,r,qL,qR));
    }
    T query(int l, int r) { return query(0,0,n,l,r); }
};

const int N = 1e5+4;
int last[N], a[N];
vector<array<int,2>> q[N];
bitset<N> ok;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    bool allOne=1;
    Segtree<int> st(n+1);
    st.update(0,n+1);
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        allOne&=(a[i]==1);
        q[i].push_back({last[a[i]]+1,a[i]});
        last[a[i]]=i;
    }
    if (allOne)
    {
        cout<<1;
        return 0;
    }
    for (int i=1;i<=n+1;++i)
        q[n+2].push_back({last[i]+1,i});
    for (int i=1;i<=n+2;++i)
    {
        if (i<=n)
            st.update(a[i],i);
        for (auto j : q[i])
            if (j[0]<=st.query(0,j[1]-1))
                ok[j[1]]=1;
    }
    for (int i=1;i<=n+2;++i)
        if (!ok[i])
        {
            cout<<i;
            return 0;
        }
    return 0;
}