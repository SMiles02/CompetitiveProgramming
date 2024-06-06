#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, l, r, s = 1;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    l = 1;
    r = n;
    for (int i = 1; i + 1 < n; i += 2) {
        if (a[i] == 1) {
            ++s;
        }
    }
    vector<array<int, 2>> v, w;
    for (int i = s; i + 1 < n; i += 2) {
        v.push_back({a[i], i});
    }
    sort(v.begin(), v.end());
    for (auto i : v) {
        b[i[1]] = r--;
    }
    for (int i = 0; i < n; ++i) {
        if (b[i] == 0) {
            w.push_back({a[i], i});
        }
    }
    sort(w.begin(), w.end());
    for (auto i : w) {
        b[i[1]] = r--;
    }
    for (int i : b) {
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