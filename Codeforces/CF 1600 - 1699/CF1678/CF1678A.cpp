#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 0, x;
    cin >> n;
    set<int> s;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        s.insert(x);
        ++m[x];
    }
    if (!m[0]) {
        if (s.size() == n)
            ++ans;
        ++ans;
    }
    ans += min(n - 1, n - m[0]);
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