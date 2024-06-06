#include <bits/stdc++.h>
using namespace std;

template <class S, S (*op)(S, S), S (*e)()> struct sparse_table {
    int n, lg;
    vector<vector<S>> st;
    sparse_table(int n) : n(n), lg((int)log2(n) + 2), st((int)log2(n) + 2, vector<int>(n, e())) {}
    void set(int i, S x) {
        st[0][i] = x;
    }
    void build() {
        for (int j = 1; j < lg; ++j) {
            for (int i = n - 1; i - (1 << j) + 1 >= 0; --i) {
                st[j][i] = op(st[j - 1][i], st[j - 1][i - (1 << (j - 1))]);
            }
        }
    }
};

int op(int a, int b) { return max(a, b); }
int e() { return -1; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m = 0;
    cin >> n;
    vector<int> a(n), dp(n, 1e9);
    sparse_table<int, op, e> st(n * 2);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m = max(m, a[i]);
        st.set(i, a[i]);
        st.set(i + n, a[i]);
    }
    st.build();
    for (int i = 0; i < n; ++i) {
        if (a[i] * 2 >= m) {
            continue;
        }
        int cur = i + n;
        for (int j = 16; j >= 0; --j) {
            if (cur - (1 << j) >= 0 && a[i] * 2 >= st.st[j][cur - 1]) {
                cur -= 1 << j;
            }
        }
        dp[(cur - 1) % n] = min(dp[(cur - 1) % n], i + n - cur + 1);
    }
    for (int _ = 0; _ < 3; ++_) {
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = min(dp[i], dp[(i + 1) % n] + 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (dp[i] == 1e9) {
            dp[i] = -1;
        }
        cout << dp[i] << " ";
    }
    cout << "\n";
    return 0;
}