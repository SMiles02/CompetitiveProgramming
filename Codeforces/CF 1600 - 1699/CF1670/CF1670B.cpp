#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    vector<bool> cr(26);
    char c;
    cin >> k;
    while (k--) {
        cin >> c;
        cr[c - 'a'] = true;
    }
    vector<int> v;
    for (int i = n - 1; i >= 0; --i)
        if (cr[s[i] - 'a']) {
            if (!v.empty())
                ans = max(ans, v.back() - i);
            v.push_back(i);
        }
    if (!v.empty())
        ans = max(ans, v.back());
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