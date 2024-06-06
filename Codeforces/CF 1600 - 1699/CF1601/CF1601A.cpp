#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, cnt = 0;
    cin >> n;
    vector<int> a(n), v(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < 30; ++j) {
        int cur = 0;
        for (int i : a) {
            if (i & (1 << j)) {
                ++cur;
            }
        }
        if (cur != 0) {
            ++cnt;
            ++v[cur];
        }
    }
    for (int i = 1; i <= n; ++i) {
        int cur = 0;
        for (int j = i; j <= n; j += i) {
            cur += v[j];
        }
        if (cur == cnt) {
            cout << i << " ";
        }
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