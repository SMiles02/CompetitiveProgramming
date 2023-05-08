#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
int a[N], g[N], p[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    g[0] = 0;
    for (int i = 1; i <= n;) {
        int j = i + 1;
        while (j <= n && a[j - 1] >= a[j])
            ++j;
        for (int k = i; k < j; ++k)
            g[k] = g[i - 1] + 1;
        p[g[i]] = p[g[i] - 1] + min(j - i, 2);
        i = j;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == r)
            cout << "1\n";
        else if (g[l] == g[r])
            cout << "2\n";
        else
            cout << p[g[r] - 1] - p[g[l]] + 2 + (g[l] == g[l + 1]) + (g[r - 1] == g[r]) << "\n";
    }
    return 0;
}