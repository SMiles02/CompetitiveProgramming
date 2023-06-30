#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, cnt = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (a[n - 1] == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        ++cnt;
        if (a[i] == 0) {
            v.push_back(cnt);
            cnt = 0;
        }
    }
    while (!v.empty()) {
        for (int j = 1; j < v.back(); ++j)
            cout << "0 ";
        cout << v.back() - 1 << " ";
        v.pop_back();
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