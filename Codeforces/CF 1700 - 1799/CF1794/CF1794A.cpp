#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n * 2 - 2; ++i) {
        string s;
        cin >> s;
        if (s.size() == n - 1)
            v.push_back(s);
    }
    reverse(v[0].begin(), v[0].end());
    if (v[0] == v[1])
        cout << "YES\n";
    else
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