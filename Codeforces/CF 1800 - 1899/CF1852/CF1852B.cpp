#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, dn = 0, cur;
    cin >> n;
    cur = n;
    int ans[n];
    deque<array<int, 2>> a;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        a.push_back({k, i});
    }
    sort(a.rbegin(), a.rend());
    while (!a.empty() && ok) {
        auto [x, i] = a[0];
        x -= dn;
        if (x > a.size() || x < 0 || a.back()[0] - dn < 0) {
            ok = false;
            break;
        }
        if (x == 0) {
            for (auto j : a) {
                ans[j[1]] = -1;
            }
            break;
        }
        while (x < a.size() && ok) {
            if (a.back()[0] - dn != 0) {
                ok = false;
            }
            ans[a.back()[1]] = -cur--;
            a.pop_back();
        }
        ans[i] = cur--;
        a.pop_front();
        ++dn;
    }
    if (ok) {
        cout << "YES\n";
        for (int i = 0;i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    else {
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