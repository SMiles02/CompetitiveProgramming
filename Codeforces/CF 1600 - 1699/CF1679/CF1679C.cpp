#include <bits/stdc++.h>
using namespace std;

template<class T> struct segtree {
    // range [0,n]

    // merge(ID,x) = x
    const T ID = 1e9;
    int n;
    vector<T> v;
    segtree(int n) : n(n), v(n*4+4, 0) {}
    T merge(T a, T b) { return min(a,b); }
    void update(int i, int l, int r, int j, T x) {
        if (j<l||r<j)
            return;
        if (l==r) {
            v[i]+=x;
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
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, t, a, b, c, d;
    cin >> n >> q;
    segtree<int> rows(n), cols(n);
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b;
            rows.update(a, 1);
            cols.update(b, 1);
        }
        else if (t == 2) {
            cin >> a >> b;
            rows.update(a, -1);
            cols.update(b, -1);
        }
        else {
            cin >> a >> b >> c >> d;
            if (rows.query(a, c) || cols.query(b, d))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}