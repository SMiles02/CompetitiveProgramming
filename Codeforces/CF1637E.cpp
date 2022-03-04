#include <bits/stdc++.h>
using namespace std;

bool cmp1(array<int, 2>& x, array<int, 2>& y) {
    return x[0] + x[1] < y[0] + y[1];
}

bool cmp2(array<int, 2>& x, array<int, 2>& y) {
    return x[0] + y[1] < y[0] + x[1];
}

bool cmp3(array<int, 2>& x, array<int, 2>& y) {
    return x[0] - x[1] < y[0] - y[1];
}

bool cmp4(array<int, 2>& x, array<int, 2>& y) {
    return 1LL * x[0] * x[1] < 1LL * y[0] * y[1];
}

bool cmp5(array<int, 2>& x, array<int, 2>& y) {
    return 1LL * x[0] * y[1] < 1LL * y[0] * x[1];
}

bool cmp6(array<int, 2>& x, array<int, 2>& y) {
    return x[1] - x[0] < y[1] - y[0];
}

const int checks = 10;
int n;
long long ans;
vector<array<int, 2>> v;
map<int, set<int>> bad;

void calc() {
    for (int i = 0; i < n; ++i)
        for (int j = n - 1, dn = 0; j >= 0 && dn < checks; --j)
            if (i != j && !bad[v[i][0]].count(v[j][0])) {
                ++dn;
                ans = max(ans, 1LL * (v[i][0] + v[j][0]) * (v[i][1] + v[j][1]));
            }
}

void solve() {
    int m, x, y;
    ans = 0;
    cin >> n >> m;
    map<int, int> mp;
    bad.clear();
    for (int i = 0; i < n; ++i) {
        cin >> x;
        ++mp[x];
    }
    while (m--) {
        cin >> x >> y;
        bad[x].insert(y);
        bad[y].insert(x);
    }
    v.clear();
    for (auto i : mp)
        v.push_back({i.first, i.second});
    n = v.size();
    sort(v.begin(), v.end(), cmp1);
    calc();
    sort(v.begin(), v.end(), cmp2);
    calc();
    sort(v.begin(), v.end(), cmp3);
    calc();
    sort(v.begin(), v.end(), cmp4);
    calc();
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