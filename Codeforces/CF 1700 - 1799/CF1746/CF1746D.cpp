#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;
int s[N];
vector<int> e[N];

array<ll, 2> dfs(int c, int l, int r) {
    array<ll, 2> ans = {1LL * l * s[c], 1LL * r * s[c]};
    if (e[c].empty())
        return ans;
    vector<ll> v;
    for (int i : e[c]) {
        array<ll, 2> tmp = dfs(i, l / e[c].size(), (r + e[c].size() - 1) / e[c].size());
        ans[0] += tmp[0];
        ans[1] += tmp[0];
        v.push_back(tmp[1] - tmp[0]);
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < l % e[c].size(); ++i) {
        ans[0] += v[i];
        ans[1] += v[i];
    }
    if (l == r)
        return {ans[0], ans[1]};
    else
        return {ans[0], ans[1] + v[l % e[c].size()]};
}

void solve() {
    int n, k, p;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    for (int i = 2; i <= n; ++i) {
        cin >> p;
        e[p].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        cin >> s[i];
    cout << dfs(1, k, k)[0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}