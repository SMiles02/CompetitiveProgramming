#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int X = 2e9;

double rnd() {
    return double(rng() % X) / X;
}

void solve() {
    int n, cur1 = 0, cur2 = 0, iter = 200000;
    double t = 50, mpl;
    mpl = pow((1e-5)/t, (double)1/iter);
    cin >> n;
    long long ans = 0, tot;
    int a[n], b[n];
    cur1 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans += ((n - 1) * a[i] + cur1 * 2) * a[i];
        cur1 += a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        ans += ((n - 1) * b[i] + cur2 * 2) * b[i];
        cur2 += b[i];
    }
    tot = ans;
    for (int _ = 0; _ < iter; ++_) {
        t *= mpl;
        int i = uniform_int_distribution<int>(0, n - 1)(rng);
        if ((a[i] - b[i]) * (cur2 - b[i]) + (b[i] - a[i]) * (cur1 - a[i]) < 0 || rnd() >= exp((double) - 1 / t)) {
            ans += ((a[i] - b[i]) * (cur2 - b[i]) + (b[i] - a[i]) * (cur1 - a[i])) * 2;
            cur1 += b[i] - a[i];
            cur2 += a[i] - b[i];
            swap(a[i], b[i]);
        }
        tot = min(tot, ans);
    }
    cout << tot << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}