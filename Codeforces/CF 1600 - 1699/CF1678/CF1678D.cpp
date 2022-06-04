#include <bits/stdc++.h>
using namespace std;

template<class T> struct segtree {
    // range [0,n]

    // merge(ID,x) = x
    const T ID = 0;
    int n;
    vector<T> v;
    segtree(int n) : n(n), v(n*4+4, ID) {}
    T merge(T a, T b) { return max(a,b); }
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

void solve() {
    int n, m, t;
    cin >> n >> m;
    string s;
    cin >> s;
    t = n * m;
    segtree<int> seg(t);
    for (int i = 0; i < t; ++i)
        seg.update(i, s[i] - '0');
    vector<int> rows(t), cols(t);
    for (int i = 0; i < m; ++i)
        for (int j = i; j < t; j += m)
            if (s[j] == '1') {
                ++cols[j];
                break;
            }
    for (int i = 1; i < t; ++i)
        cols[i] += cols[i - 1];
    for (int i = 0; i < m; ++i)
        rows[i] = seg.query(0, i);
    for (int i = m; i < t; ++i)
        rows[i] = rows[i - m] + seg.query(i - m + 1, i);
    for (int i = 0; i < t; ++i)
        cout << rows[i] + cols[i] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}