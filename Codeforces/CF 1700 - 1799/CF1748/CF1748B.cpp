#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        int uni = 0, mx = 0;
        vector<int> cnt(10);
        for (int j = i; j - i < 100 && j < n; ++j) {
            uni += (cnt[s[j] - '0']++ == 0);
            mx = max(mx, cnt[s[j] - '0']);
            ans += (mx <= uni);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}