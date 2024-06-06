#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), ans;
    for (auto &ai : a) {
        cin >> ai;
    }
    ans.push_back(a[0]);
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            ans.push_back(1);
        }
        ans.push_back(a[i]);
    }
    cout << ans.size() << "\n";
    for (auto ai : ans) {
        cout << ai << " ";
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