#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1), l(n), r(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    map<int, int> p, q;
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (p[a[i]] == 0) {
            l[i] = 1;
        }
        else {
            l[i] = p[a[i]] + 1;
        }
        p[a[i]] = i;
    }
    for (int i = n; i >= 1; --i) {
        if (q[a[i]] == 0) {
            r[i] = n;
        }
        else {
            r[i] = q[a[i]] - 1;
        }
        q[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        ans += 1LL * (i - l[i] + 1) * (r[i] - i + 1);
        cout << (i - l[i] + 1) << " " << (r[i] - i + 1) << endl;
    }
    cout << ans;
    return 0;
}