#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n * 2), v;
    vector<ll> a(n + 1), p(n + 1);
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        a[i] = p[i] - p[i - 1];
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] > n * 2 - 1) {
            cout << "NO\n";
            return;
        }
        ++cnt[a[i]];
    }
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 0) {
            v.push_back(i);
        }
    }
    if (v.size() < 1 || 2 < v.size()) {
        cout << "NO\n";
        return;
    }
    if (v.size() == 1 || cnt[v[0] + v[1]] - (v[0] + v[1] <= n) == 1) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}