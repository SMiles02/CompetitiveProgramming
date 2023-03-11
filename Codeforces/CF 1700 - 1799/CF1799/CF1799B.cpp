#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    array<int, 2> a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        a[i][1] = i + 1;
    }
    sort(a, a + n);
    vector<array<int, 2>> ans;
    for (int _ = 0; _ < 30; ++_) {
        for (int i = 1; i < n; ++i)
            if (a[i][0] != a[0][0]) {
                ans.push_back({a[i][1], a[0][1]});
                a[i][0] = (a[i][0] + a[0][0] - 1) / a[0][0];
            }
        sort(a, a + n);
    }
    if (a[0][0] != a[n - 1][0]) {
        cout << "-1\n";
        return;
    }
    cout << ans.size() << "\n";
    for (auto i : ans)
        cout << i[0] << " " << i[1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}