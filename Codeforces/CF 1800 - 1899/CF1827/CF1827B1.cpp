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

// basic operation
int op(int a, int b) { return max(a, b); }

// op(anything, e()) = anything
int e() { return -1; }

const int L = 18;

void clear(stack<int>& s) {
    while (!s.empty()) {
        s.pop();
    }
}

void solve() {
    int n;
    cin >> n;
    long long ans = 0;
    vector<int> a(n), pmax(n), xl(n), xr(n), yl(n);
    sparse_table<int, op, e> st(n);
    stack<int> s;
    // x lesser, y greater
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        st.set(i, a[i]);
        ans += (1LL * i * (i + 1)) / 2;
        if (i == 0) {
            pmax[i] = a[i];
        }
        else {
            pmax[i] = max(pmax[i - 1], a[i]);
        }
    }
    st.build();
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && a[i] < a[s.top()]) {
            s.pop();
        }
        if (s.empty()) {
            xl[i] = -1;
        }
        else {
            xl[i] = s.top();
        }
        s.push(i);
    }
    clear(s);
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && a[i] < a[s.top()]) {
            s.pop();
        }
        if (s.empty()) {
            xr[i] = n;
        }
        else {
            xr[i] = s.top();
        }
        s.push(i);
    }
    clear(s);
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && a[i] > a[s.top()]) {
            s.pop();
        }
        if (s.empty()) {
            yl[i] = -1;
        }
        else {
            yl[i] = s.top();
        }
        s.push(i);
    }
    for (int i = 0; i < n; ++i) {
        if (xl[i] == -1) {
            continue;
        }
        // cout << i << " !\n";
        int k = xl[i], p = k, q = xr[i];
        for (int j = L; j >= 0; --j) {
            if (p - (1 << j) >= 0 && st.st[j][p - 1] < a[i]) {
                p -= 1 << j;
            }
        }
        --p;
        ans -= (k - p) * (q - i);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}