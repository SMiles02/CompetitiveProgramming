#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, s, t;
    cin >> n >> m;
    int a[n + 1];
    long long p[n + 1][2] = {0};
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i][0] = p[i - 1][0] + max(0, a[i - 1] - a[i]);
        p[i][1] = p[i - 1][1] + max(0, a[i] - a[i - 1]);
    }
    while (m--) {
        cin >> s >> t;
        cout << p[max(s, t)][s > t] - p[min(s, t)][s > t] << "\n";
    }
    return 0;
}