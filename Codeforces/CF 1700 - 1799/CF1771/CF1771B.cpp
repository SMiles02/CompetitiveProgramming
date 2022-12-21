#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 2;
int b[N];

void solve() {
    int n, m, x, y, r = 0;
    ll ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n + 1; ++i)
        b[i] = n + 1;
    while (m--) {
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        b[x] = min(b[x], y);
    }
    multiset<int> s;
    for (int i = 1; i <= n; ++i) {
        if (i > 1)
            s.erase(s.lower_bound(b[i - 1]));
        while (r + 1 <= n && (s.empty() || s.find(r + 1) == s.end()))
            s.insert(b[++r]);
        ans += r - i + 1;
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