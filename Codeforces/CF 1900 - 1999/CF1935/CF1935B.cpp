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
    int n, lb, rb;
    cin >> n;
    vector<int> a(n), l(n + 1, n), r(n + 1, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
    }
    lb = 0;
    rb = n - 1;
    for (int i = 0; i <= n; ++i) {
        if (l[i] == n) {
            if (lb < rb) {
                cout << "2\n1 " << lb + 1 << "\n" << lb + 2 << " " << n << "\n";
            }
            else {
                cout << "-1\n";
            }
            return;
        }
        lb = max(lb, l[i]);
        rb = min(rb, r[i]);
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