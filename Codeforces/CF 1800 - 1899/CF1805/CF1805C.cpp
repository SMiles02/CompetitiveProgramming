#include <bits/stdc++.h>
using namespace std;

bool no_sol(int a, int b, int c) {
    return 1LL * b * b - 4LL * a * c < 0;
}

void solve() {
    int n, m, a, b, c, k;
    cin >> n >> m;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        s.insert(k);
    }
    while (m--) {
        cin >> a >> b >> c;
        if (s.lower_bound(b) != s.end() && no_sol(a, b - *s.lower_bound(b), c))
            cout << "YES\n" << *s.lower_bound(b) << "\n";
        else if (s.lower_bound(b) != s.begin() && no_sol(a, b - *(--s.lower_bound(b)), c))
            cout << "YES\n" << *(--s.lower_bound(b)) << "\n";
        else
            cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}