#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 20;
vector<int> works[N];
bitset<N> e[N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> v(m);
    for (int i = 0; i < m; ++i) {
        cin >> v[i][0] >> v[i][1];
    }
    if (n >= 20) {
        cout << n << "\n";
        for (int i = 1; i <= n; ++i) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            e[i][j] = 0;
        }
    }
    for (int i = 0; i < m; ++i) {
        e[v[i][0] - 1][v[i][1] - 1] = 1;
    }
    for (int cnf : works[n]) {
        bool ok = true;
        for (int i = 0; i < n && cnf; ++i) {
            for (int j = 0; j < n; ++j) {
                if (e[i][j] && (cnf & (1 << i)) && !(cnf & (1 << j))) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            cout << __builtin_popcount(cnf) << "\n";
            for (int i = 0; i < n; ++i) {
                if (cnf & (1 << i)) {
                    cout << i + 1 << " ";
                }
            }
            cout << "\n";
            return;
        }
    }
    cout << "-1\n";
}

void gen(int n) {
    int cnt = 0;
    for (int i = 1; i < (1 << n); ++i) {
        int on = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                for (int k = j; k < n; k += j + 1) {
                    on ^= 1 << k;
                }
            }
        }
        if (__builtin_popcount(on) <= n / 5) {
            works[n].push_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 1; i <= 19; ++i) {
        gen(i);
    }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}