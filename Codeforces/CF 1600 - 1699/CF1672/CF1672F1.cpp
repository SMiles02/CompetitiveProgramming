#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, mx = 1;
    cin >> n;
    vector<array<int, 2>> a(n);
    vector<int> ans(n);
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        a[i][1] = i;
        mx = max(mx, ++m[a[i][0]]);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
        ans[a[(i + mx) % n][1]] = a[i][0];
    for (auto i : ans)
        cout << i << " ";
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