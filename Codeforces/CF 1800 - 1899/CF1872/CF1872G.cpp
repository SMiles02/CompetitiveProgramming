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
    int n, l, r;
    cin >> n;
    vector<int> a(n + 1);
    vector<ll> p(n + 1);
    bool all_one = true;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        all_one &= a[i] == 1;
        p[i] = p[i - 1] + a[i];
    }
    if (all_one) {
        cout << "1 1\n";
        return;
    }
    l = 1;
    r = n;
    while (a[l] == 1) {
        ++l;
    }
    while (a[r] == 1) {
        --r;
    }
    ll prod = 1;
    for (int i = l; i <= r; ++i) {
        prod = min(prod * a[i], (ll)2e9);
    }
    if (prod == 2e9) {
        cout << l << " " << r << "\n";
        return;
    }
    vector<array<int, 3>> segs;
    int start = -1, cur_prod = 1;
    for (int i = l; i <= r; ++i) {
        if (start == -1 && a[i] > 1) {
            start = i;
            cur_prod = 1;
        }
        if (start != -1) {
            cur_prod *= a[i];
            if (i == r || a[i + 1] == 1) {
                segs.push_back({start, i, cur_prod});
                // cout << start << " " << i << " " << cur_prod << "\n";
                start = -1;
            }
        }
    }
    array<int, 3> ans = {(int)p[n], 1, 1};
    for (int i = 0; i < segs.size(); ++i) {
        cur_prod = 1;
        for (int j = i; j < segs.size(); ++j) {
            cur_prod *= segs[j][2];
            ans = max(ans, {(int)(p[n] - p[segs[j][1]] + p[segs[i][0] - 1] + cur_prod), segs[i][0], segs[j][1]});
        }
    }
    // cout << ans[0] << "\n";
    cout << ans[1] << " " << ans[2] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}