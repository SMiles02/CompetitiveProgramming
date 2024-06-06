#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    string s, t;
    cin >> s;
    cin >> t;
    vector<int> p(n + 1);
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; i + j < n && j < m; ++j) {
            cnt += s[i + j] == t[j];
        }
        p[i + 1] = p[i] + (cnt == m);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << p[max(r - m + 1, l - 1)] - p[l - 1] << "\n";
    }
    return 0;
}