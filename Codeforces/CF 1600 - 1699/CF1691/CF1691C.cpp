#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, x = 0, y;
    cin >> n >> k;
    string s;
    cin >> s;
    for (auto i : s)
        x += (i == '0');
    y = n - x;
    if (s[n - 1] == '0' && y) {
        for (int i = n - 2; i >= 0; --i)
            if (s[i] == '1' && n - 1 - i <= k) {
                swap(s[i], s[n - 1]);
                k -= n - 1 - i;
                break;
            }
    }
    if (s[0] == '0' && y - (s[n - 1] == '1')) {
        for (int i = 1; i < n; ++i)
            if (s[i] == '1' && i <= k) {
                swap(s[i], s[0]);
                k -= i;
                break;
            }
    }
    cout << 11 * y - (s[0] - '0') - (s[n - 1] - '0') * 10 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}