#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k, ans = 0, always_dry = 0;
    cin >> n >> m >> k;
    vector<int> p(n + 2), one(m + 1);
    vector<vector<array<int, 2>>> start_here(n + 1);
    map<array<int, 2>, int> two;
    for (int i = 1, lx, rx; i <= m; ++i) {
        cin >> lx >> rx;
        ++p[lx];
        --p[rx + 1];
        start_here[lx].push_back({i, rx});
    }
    vector<int> l(n + 1), r(n + 1);
    priority_queue<array<int, 2>> find_max;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> find_min;
    for (int i = 1; i <= n; ++i) {
        for (auto j : start_here[i]) {
            find_min.push(j);
            find_max.push(j);
        }
        while (!find_min.empty() && find_min.top()[1] < i) {
            find_min.pop();
        }
        while (!find_max.empty() && find_max.top()[1] < i) {
            find_max.pop();
        }
        if (!find_min.empty()) {
            l[i] = find_min.top()[0];
            r[i] = find_max.top()[0];
        }
    }
    for (int i = 1; i <= n; ++i) {
        p[i] += p[i - 1];
        if (p[i] == 0) {
            ++always_dry;
        }
        else if (p[i] == 1) {
            ++one[l[i]];
        }
        else if (p[i] == 2) {
            ++two[{l[i], r[i]}];
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (p[i] == 2) {
            ans = max(ans, two[{l[i], r[i]}] + one[l[i]] + one[r[i]]);
        }
    }
    sort(one.rbegin(), one.rend());
    ans = max(ans, one[0] + one[1]);
    cout << ans + always_dry << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}