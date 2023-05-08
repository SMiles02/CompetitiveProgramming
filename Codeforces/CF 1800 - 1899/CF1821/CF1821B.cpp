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
    int n, l, r, mn, mx;
    cin >> n;
    l = n;
    r = 0;
    int a[n], b[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (a[i] != b[i]) {
            l = min(l, i);
            r = max(r, i);
        }
    }
    mn = mx = a[l];
    for (int i = l + 1; i <= r; ++i) {
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    while ((0 <= l - 1 && a[l - 1] <= mn) || (r + 1 < n && mx <= a[r + 1])) {
        if (0 <= l - 1 && a[l - 1] <= mn)
            mn = a[--l];
        else
            mx = a[++r];
    }
    cout << l + 1 << " " << r + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}