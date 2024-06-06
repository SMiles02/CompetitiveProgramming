#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<array<int, 3>> v;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == -1) {
            if (i > 0 && v.back()[0] == -1) {
                v.back()[2] = i;
            }
            else {
                v.push_back({-1, i, i});
            }
        }
        else {
            v.push_back({a[i], i, i});
        }
    }
    if (v.size() == 1 && v[0][0] == -1) {
        for (int i = 0; i < n; ++i) {
            cout << (i & 1) + 1 << " ";
        }
        cout << "\n";
        return;
    }
    if (v[0][0] == -1) {
        for (int i = v[0][2]; i >= 0; --i) {
            if (a[i + 1] == 1) {
                a[i] = 2;
            }
            else {
                a[i] = a[i + 1] / 2;
            }
        }
    }
    if (v.back()[0] == -1) {
        for (int i = v.back()[1]; i < n; ++i) {
            if (a[i - 1] == 1) {
                a[i] = 2;
            }
            else {
                a[i] = a[i - 1] / 2;
            }
        }
    }
    for (int i = 1; i + 1 < v.size(); ++i) {
        if (v[i][0] != -1) {
            continue;
        }
        int l = v[i][1] - 1, r = v[i][2] + 1;
        while (l + 1 < r) {
            if (a[l] == a[r]) {
                a[++l] = a[r] * 2;
            }
            else if (a[l] < a[r]) {
                a[r - 1] = a[r] / 2;
                --r;
            }
            else {
                a[l + 1] = a[l] / 2;
                ++l;
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        if (max(a[i - 1], a[i]) / 2 != min(a[i - 1], a[i])) {
            cout << "-1\n";
            return;
        }
    }
    for (int i : a) {
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