#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        s.insert(k);
    }
    cout << s.size() - ((n + s.size()) & 1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}