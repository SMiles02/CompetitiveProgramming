#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, ans(n, '!');
    cin >> s;
    vector<int> f(26);
    for (auto i : s) {
        ++f[i - 'a'];
    }
    vector<array<int, 2>> v(26);
    for (int i = 0; i < 26; ++i) {
        v[i] = {f[i], i};
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i += 2) {
        if (v.back()[0] == 0) {
            v.pop_back();
        }
        ans[i] = 'a' + v.back()[1];
        --v.back()[0];
    }
    for (int i = 1; i < n; i += 2) {
        if (v.back()[0] == 0) {
            v.pop_back();
        }
        ans[i] = 'a' + v.back()[1];
        --v.back()[0];
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