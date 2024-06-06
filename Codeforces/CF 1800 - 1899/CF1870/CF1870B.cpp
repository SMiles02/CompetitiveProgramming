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
    int n, m, x = 0;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        x ^= a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    if (n % 2 == 0) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < 30; ++j) {
                if ((b[i] & (1 << j))) {
                    x ^= x & (1 << j);
                }
            }
        }
    }
    cout << x << " ";
    if (n & 1) {
        for (int i = 0; i < m; ++i) {
            x |= b[i];
        }
    }
    else {
        x = 0;
        for (int i = 0; i < n; ++i) {
            x ^= a[i];
        }
    }
    cout << x << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}