#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size(), x = n - 1;
    vector<bool> found(26);
    for (int i = n - 1; i >= 0; --i)
        if (!found[s[i] - 'a']) {
            found[s[i] - 'a'] = 1;
            x = i;
        }
    for (int i = x; i < n; ++i)
        cout << s[i];
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