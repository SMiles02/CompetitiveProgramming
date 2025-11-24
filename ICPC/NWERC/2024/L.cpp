#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;

bool check(int k, vector<int> a, vector<int> b) {
    for (int i = n - 1; i >= k; --i) {
        for (int j = 0; j < x && !b.empty() && b.back() <= a[i]; ++j) {
            b.pop_back();
        }
    }
    for (int i = k - 1; i >= 0; --i) {
        for (int j = 0; j < y && !b.empty() && b.back() <= a[i]; ++j) {
            b.pop_back();
        }
    }
    return b.empty();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x >> y;
    int l = 0, r = n, mid;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (!check(0, a, b)) {
        cout << "impossible\n";
        return 0;
    }
    while (l < r) {
        mid = l + (r - l) / 2 + 1;
        if (check(mid, a, b)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}