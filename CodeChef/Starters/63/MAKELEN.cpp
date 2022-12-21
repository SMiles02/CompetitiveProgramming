#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<array<int, 2>> v = {{s[0] - '0', 1}};
    for (int i = 1; i < n; ++i) {
        if (s[i] - '0' == v.back()[0])
            ++v.back()[1];
        else
            v.push_back({s[i] - '0', 1});
    }
    if (n == 1 && s == "1") {
        cout << "YES\n";
        return;
    }
    for (auto i : v)
        if (i[0] == 1 && (i[1] & 1)) {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}