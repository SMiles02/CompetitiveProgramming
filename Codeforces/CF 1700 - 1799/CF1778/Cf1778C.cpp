#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    long long ans = 0, cur;
    cin >> n >> k;
    string a, b;
    cin >> a;
    cin >> b;
    set<char> s;
    vector<char> v;
    for (auto i : a)
        s.insert(i);
    for (auto i : s)
        v.push_back(i);
    if (v.size() <= k) {
        cout << (1LL * n * (n + 1)) / 2 << "\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        int id;
        bool same = a[i] == b[i];
        for (int j = 0; j < v.size(); ++j)
            if (a[i] == v[j])
                id = j;
        a[i] = 'a' + id;
        if (same)
            b[i] = a[i];
        else
            b[i] = 'z';
    }
    for (int j = 0; j < (1 << v.size()); ++j)
        if (__builtin_popcount(j) == k) {
            int l = 0;
            cur = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] == b[i] || ((1 << (a[i] - 'a')) & j)) {
                    ++l;
                    cur += l;
                }
                else
                    l = 0;
            }
            ans = max(ans, cur);
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