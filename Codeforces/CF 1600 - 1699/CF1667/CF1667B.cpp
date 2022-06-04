#include <bits/stdc++.h>
#define ll long long
using namespace std;

template<class T> struct segtree {
    // range [0,n]

    // merge(ID,x) = x
    const T ID = -1e9;
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
    int n, l, r, m;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), dp(n + 1);
    vector<array<ll, 2>> v(n + 1);
    vector<ll> p(n + 1);
    segtree<int> seg(n);
    v[0] = {0, 0};
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
        v[i] = {p[i], i};
    }
    sort(v.begin(), v.end());
    for (int i = 0; i <= n; ++i)
        b[v[i][1]] = i;
    seg.update(b[0], 0);
    for (int i = 1; i <= n; ++i) {
        if (a[i] > 0)
            dp[i] = dp[i - 1] + 1;
        else if (a[i] < 0)
            dp[i] = dp[i - 1] - 1;
        else
            dp[i] = dp[i - 1];
        if (p[i] != v[0][0]) {
            l = 0;
            r = b[i] - 1;
            while (l < r) {
                m = l + (r - l) / 2 + 1;
                if (v[m][0] < p[i])
                    l = m;
                else
                    r = m - 1;
            }
            dp[i] = max(dp[i], i + seg.query(0, l));
        }
        seg.update(b[i], dp[i] - i);
    }
    cout << dp[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}