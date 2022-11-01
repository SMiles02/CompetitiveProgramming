#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, c = 0, x, zero_count = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    x = min(k, 20);
    for (int i = 0; i < k - x; ++i)
        zero_count += (s[i] == '0');
    for (int i = k - x; i < k; ++i) {
        c <<= 1;
        if (s[i] == '0')
            ++c;
    }
    set<int> banned;
    if (zero_count == 0)
        banned.insert(c);
    for (int i = k; i < n; ++i) {
        c = (c << 1) & ((1 << x) - 1);
        if (s[i] == '0')
            ++c;
        if (x != k) {
            zero_count -= (s[i - k] == '0');
            zero_count += (s[i - x] == '0');
        }
        if (zero_count == 0)
            banned.insert(c);
    }
    for (int i = 0; i < (1 << x); ++i)
        if (!banned.count(i)) {
            cout << "YES\n";
            for (int j = 0; j < k - x; ++j)
                cout << 0;
            for (int j = (1 << (x - 1)); j > 0; j >>= 1)
                cout << min(i & j, 1);
            cout << "\n";
            return;
        }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}