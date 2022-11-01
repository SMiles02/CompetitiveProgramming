#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        s.insert(x);
    }
    if (s.size() == n)
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