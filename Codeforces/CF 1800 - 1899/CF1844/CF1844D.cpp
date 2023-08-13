#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v;
    string ans = "";
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            v.push_back(i);
            v.push_back(n / i);
        }
    }
    for (int i = 0; i < n; ++i) {
        vector<bool> done(26);
        for (int j : v) {
            if (i >= j) {
                done[ans[i - j] - 'a'] = true;
            }
        }
        for (int j = 0; j < 26; ++j) {
            if (!done[j]) {
                ans += (char)('a' + j);
                break;
            }
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