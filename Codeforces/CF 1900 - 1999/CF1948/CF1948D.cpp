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
    string s;
    cin >> s;
    int n = s.size(), ans = 0;
    for (int i = 1; i * 2 <= n; ++i) {
        vector<bool> b(n);
        for (int j = 0; j + i < n; ++j) {
            if (!(s[j] != '?' && s[j + i] != '?' && s[j] != s[j + i])) {
                b[j] = true;
            }
        }
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            if (b[j]) {
                ++cur;
                if (cur == i) {
                    ans = i * 2;
                }
            }
            else {
                cur = 0;
            }
        }
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