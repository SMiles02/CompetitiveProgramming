#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, x = 0, cnt = 0, last = 0;
    cin >> n >> m;
    long long tot = 0;
    vector<int> a(n + m + 1), b(n + m + 1);
    vector<long long> ans(n + m + 1);
    for (int i = 0; i < n + m + 1; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n + m + 1; ++i) {
        cin >> b[i];
        x += a[i] > b[i];
    }
    if (x <= n) {
        swap(a, b);
        swap(n, m);
    }
    for (int i = 0; i < n + m + 1; ++i) {
        if (a[i] > b[i] && cnt < n + 1) {
            ++cnt;
            last = i;
            tot += a[i];
        }
        else {
            tot += b[i];
        }
    }
    for (int i = 0; i < n + m + 1; ++i) {
        if (a[i] > b[i] && i <= last) {
            ans[i] = tot - a[i];
        }
        else {
            ans[i] = tot - b[i] + b[last] - a[last];
        }
    }
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << "\n";
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