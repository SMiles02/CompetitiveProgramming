#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 2;
int x[N], p[N], s[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, a, b, c, ans = 0;
    cin >> n >> k;
    cin >> x[1] >> a >> b >> c;
    for (int i = 2; i <= n; ++i) {
        x[i] = (1LL * x[i - 1] * a + b) % c;
    }
    for (int i = 1; i <= n; ++i) {
        if (i % k == 1) {
            p[i] = x[i];
        }
        else {
            p[i] = x[i] | p[i - 1];
        }
    }
    for (int i = n; i >= 1; --i) {
        if (i % k == 0) {
            s[i] = x[i];
        }
        else {
            s[i] = x[i] | s[i + 1];
        }
    }
    for (int i = k; i <= n; ++i) {
        if (k == 1) {
            ans ^= x[i];
        }
        else {
            ans ^= p[i] | s[i - k + 1];
        }
    }
    cout << ans;
    return 0;
}