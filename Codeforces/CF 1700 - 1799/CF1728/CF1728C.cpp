#include <bits/stdc++.h>
using namespace std;

int f(int x) {
    int cnt = 0;
    while (x > 0) {
        ++cnt;
        x /= 10;
    }
    return cnt;
}

void solve() {
    int n, k, ans = 0;
    cin >> n;
    multiset<array<int, 2>> s;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        s.insert({k, 0});
    }
    for (int i = 0; i < n; ++i) {
        cin >> k;
        s.insert({k, 1});
    }
    while (!s.empty()) {
        array<int, 2> a = *--s.end();
        s.erase(--s.end());
        if (s.find({a[0], 1 - a[1]}) != s.end())
            s.erase(s.lower_bound({a[0], 1 - a[1]}));
        else {
            ++ans;
            s.insert({f(a[0]), a[1]});
        }
    }
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