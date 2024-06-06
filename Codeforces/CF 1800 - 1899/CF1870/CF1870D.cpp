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
    int n, k, cur;
    cin >> n;
    vector<int> a(n + 1), p(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 1; --i) {
        a[i] = min(a[i], a[i + 1]);
    }
    cin >> k;
    cur = k / a[1];
    k %= a[1];
    cout << cur << " ";
    for (int i = 2; i <= n; ++i) {
        int l = 0, r = cur, m;
        while (l < r) {
            m = l + (r - l) / 2 + 1;
            if (k >= 1LL * (a[i] - a[i - 1]) * m) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }
        k -= 1LL * (a[i] - a[i - 1]) * l;
        cur = l;
        cout << cur << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}