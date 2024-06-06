#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n + 1);
    vector<array<int, 2>> l(n + 1, {0, 0});
    set<int> s, t;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (l[a[i]][0] == 0) {
            s.insert(i);
        }
        else {
            int tmp1 = -1;
            if (s.count(l[a[i]][0])) {
                s.erase(l[a[i]][0]);
                tmp1 = l[a[i]][0];
            }
            if (s.empty() || *(--s.end()) < min(l[a[i]][0], *t.begin())) {
                // cerr << i << " !\n";
                ++ans;
                s.insert(i);
                if (tmp1 != -1) {
                    s.insert(tmp1);
                }
                a[i] = -1;
                continue;
            }
            t.insert(l[a[i]][0]);
        }
        l[a[i]][1] = l[a[i]][0];
        l[a[i]][0] = i;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}