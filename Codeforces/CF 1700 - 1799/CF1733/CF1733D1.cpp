#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    string s, t;
    cin >> s;
    cin >> t;
    vector<int> v;
    for (int i = 0; i < n; ++i)
        if (s[i] != t[i])
            v.push_back(i);
    if (((int)v.size()) & 1)
        cout << "-1\n";
    else if (v.size() == 2 && v[0] + 1 == v[1])
        cout << min(x, y * 2) << "\n";
    else
        cout << 1LL * y * (v.size() / 2) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}