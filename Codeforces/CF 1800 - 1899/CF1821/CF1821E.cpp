#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k, n;
    long long ans = 0;
    cin >> k;
    string s;
    cin >> s;
    n = s.size();
    vector<long long> v;
    vector<int> w;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(')
            w.push_back(0);
        else {
            int cur = w.back();
            v.push_back(cur);
            ans += cur;
            w.pop_back();
            if (!w.empty())
                w.back() += cur + 1;
        }
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < min(k, (int)v.size()); ++i)
        ans -= v[i];
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