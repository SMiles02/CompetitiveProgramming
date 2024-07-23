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
    long long m, ans = 0;
    cin >> n >> m;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i][1];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        long long cnt = min(m / a[i][0], (long long)a[i][1]), cur, tmp;
        cur = cnt * a[i][0];
        if (i + 1 < n && a[i][0] + 1 == a[i + 1][0]) {
            tmp = min((m - cur) / a[i + 1][0], (long long)a[i + 1][1]);
            cur += tmp * a[i + 1][0];
            cur += min({cnt, a[i + 1][1] - tmp, m - cur});
        }
        ans = max(ans, cur);
    }
    cout << min(ans, m) << "\n";
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