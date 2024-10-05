#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int n;
    double ans = 0;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
        ans = max(ans, double(i + 1) / a[i][1]);
    }
    for (int i = 0; i < n; ++i) {
        if (double(i + 1) / ans < a[i][0] || a[i][1] < double(i + 1) / ans) {
            cout << "-1\n";
            return;
        }
    }
    cout << fixed << setprecision(10) << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}