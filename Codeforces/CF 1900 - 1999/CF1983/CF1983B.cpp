#include <bits/stdc++.h>
using namespace std;
 
vector<int> solve_grid(int n, int m, vector<string>& a) {
    vector<int> v(n + m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            v[i] += a[i][j] - '0';
            v[j + n] += a[i][j] - '0';
        }
    }
    return v;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> v = solve_grid(n, m, a), w = solve_grid(n, m, b);
    for (int i = 0; i < n + m; ++i) {
        if (v[i] % 3 != w[i] % 3) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
