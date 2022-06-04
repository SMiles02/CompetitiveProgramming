#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    array<int, 3> a[n];
    int b[n];
    vector<array<int, 2>> ans;
    for (int i = 0; i < n; ++i)
        cin >> a[i][0];
    for (int i = 0; i < n; ++i) {
        cin >> a[i][1];
        a[i][2] = i;
    }
    sort(a, a + n);
    for (int i = 1; i < n; ++i)
        if (a[i - 1][1] > a[i][1]) {
            cout << "-1\n";
            return;
        }
    for (int i = 0; i < n; ++i)
        b[a[i][2]] = i;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (b[j] == i) {
                ans.push_back({i + 1, j + 1});
                swap(b[i], b[j]);
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