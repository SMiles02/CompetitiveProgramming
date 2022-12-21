#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 1;
ll c;
int n, d, a[N];

bool check(int k) {
    ll score = 0;
    for (int i = 0; i < min(n, k); ++i) {
        if (i + (d / k) * k < d)
            score += 1LL * a[i] * (d / k + 1);
        else
            score += 1LL * a[i] * (d / k);
    }
    return score >= c;
}

void solve() {
    cin >> n >> c >> d;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    if (!check(1)) {
        cout << "Impossible\n";
        return;
    }
    int l = 1, r = d, m;
    while (l < r) {
        m = l + (r - l) / 2 + 1;
        if (check(m))
            l = m;
        else
            r = m - 1;
    }
    if (l == d)
        cout << "Infinity\n";
    else
        cout << l - 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}