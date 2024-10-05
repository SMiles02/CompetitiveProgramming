#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int find_max(vector<int>& a, vector<int>& b) {
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        ans = max(ans, a[i] + b[i]);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n & 1) {
        int ans = n;
        vector<vector<vector<int>>> a(n + 2, vector<vector<int>>(2, vector<int>(26))), b(n + 4, vector<vector<int>>(2, vector<int>(26)));
        for (int i = 0; i < n; ++i) {
            a[i + 1] = a[i];
            ++a[i + 1][i & 1][s[i] - 'a'];
        }
        for (int i = n - 1; i >= 0; --i) {
            b[i + 1] = b[i + 2];
            ++b[i + 1][i & 1][s[i] - 'a'];
        }
        for (int i = 1; i <= n; ++i) {
            ans = min(ans, n - find_max(a[i - 1][0], b[i + 1][1]) - find_max(a[i - 1][1], b[i + 1][0]));
        }
        cout << ans << "\n";
    }
    else {
        vector<vector<int>> f(2, vector<int>(26));
        for (int i = 0; i < n; ++i) {
            ++f[i & 1][s[i] - 'a'];
        }
        sort(f[0].rbegin(), f[0].rend());
        sort(f[1].rbegin(), f[1].rend());
        cout << n - f[0][0] - f[1][0] << "\n";
    }
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