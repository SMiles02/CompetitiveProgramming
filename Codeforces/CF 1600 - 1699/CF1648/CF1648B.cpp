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
    int n, c;
    cin >> n >> c;
    vector<bool> a(c + 1);
    vector<int> p(c + 1);
    bool ok = true;
    for (int i = 0, k; i < n; ++i) {
        cin >> k;
        a[k] = true;
    }
    for (int i = 1; i <= c; ++i) {
        p[i] = p[i - 1] + a[i];
    }
    for (int i = 1; i <= c; ++i) {
        if (a[i]) {
            for (int j = 1; i * j <= c; ++j) {
                if (p[min(c, i * (j + 1) - 1)] - p[i * j - 1] > 0 && !a[j]) {
                    ok = false;
                }
            }
        }
    }
    if (ok) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}