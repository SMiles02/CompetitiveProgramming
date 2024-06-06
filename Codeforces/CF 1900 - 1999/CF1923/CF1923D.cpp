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

const int INF = 1e6;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<ll> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = b[i - 1] + (a[i] != a[i - 1]);
        p[i] = p[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i) {
        if ((i > 1 && a[i - 1] > a[i]) || (i + 1 <= n && a[i + 1] > a[i])) {
            cout << "1 ";
            continue;
        }
        int x = INF, y = INF, l, r, m;
        // x
        l = 0;
        r = i - 2;
        while (l < r) {
            m = l + (r - l) / 2 + 1;
            if (p[i - 1] - p[m - 1] > a[i] && b[i - 1] != b[m]) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }
        if (0 < l) {
            x = i - l;
        }
        // y
        l = i + 2;
        r = n + 1;
        while (l < r) {
            m = l + (r - l) / 2;
            // cerr << l << " " << r << " " << m << endl;
            if (p[m] - p[i] > a[i] && b[i + 1] != b[m]) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        // cerr << l << "\n";
        if (l <= n) {
            y = l - i;
        }
        if (min(x, y) == INF) {
            cout << "-1 ";
        }
        else {
            cout << min(x, y) << " ";
        }
        // cerr << i << ": " << x << " " << y << "\n";
    }
    cout << "\n";
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