#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

void solve() {
    int n, k, l = 1, r, m;
    cin >> n >> k;
    int a[n], ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        l = max(l, a[i]);
    }
    r = l + k;
    while (l < r) {
        m = l + (r - l) / 2 + 1;
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            ll cur_cost = m - a[i];
            int cur = m;
            for (int j = i + 1; j < n && !ok; ++j) {
                --cur;
                cur_cost += max(cur - a[j], 0);
                if (cur_cost <= k && (a[j] >= cur || (j + 1 < n && cur <= a[j + 1]))) {
                    ok = true;
                }
            }
        }
        if (ok) {
            l = m;
        }
        else {
            r = m - 1;
        }
    }
    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}