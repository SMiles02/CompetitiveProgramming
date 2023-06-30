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
    int n;
    cin >> n;
    string s, t, u;
    cin >> s;
    cin >> t;
    u = t;
    reverse(u.begin(), u.end());
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            ++ans1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] != u[i]) {
            ++ans2;
        }
    }
    int ans = n * 2;
    if (ans2 == 0) {
        ans2 = 1;
    }
    if (s == t)
        ans = 0;
    if (ans1 & 1)
        ans = min(ans, ans1 * 2 - 1);
    else
        ans = min(ans, ans1 * 2);
    if (ans2 & 1)
        ans = min(ans, ans2 * 2);
    else
        ans = min(ans, ans2 * 2 - 1);
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