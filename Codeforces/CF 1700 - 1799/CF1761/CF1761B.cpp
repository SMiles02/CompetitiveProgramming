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
    if (s.size() == 2)
        cout << n / 2 + 1 << "\n";
    else
        cout << n << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}