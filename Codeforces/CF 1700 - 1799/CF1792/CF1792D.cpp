#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 5e4 + 1, M = 10, NADA = -1;
int n, m;

void solve() {
    cin >> n >> m;
    array<int, M> a[n];
    set<array<int, M>> s;
    array<int, M> cur;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            --a[i][j];
            cur[j] = NADA;
        }
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < m; ++k)
                if (a[i][k] == j)
                    cur[j] = k;
            s.insert(cur);
        }
    }
    for (int i = 0; i < n; ++i) {
        int ans = 0;
        for (int j = 0; j < m; ++j)
            cur[j] = NADA;
        for (int j = 0; j < m; ++j) {
            cur[j] = a[i][j];
            if (s.count(cur))
                ans = j + 1;
        }
        cout << ans << " ";
    }
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