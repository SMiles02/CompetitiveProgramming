#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x, k;
    cin >> n >> x;
    long long s = 0, l = 1, r = 1e12, m;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        s += k;
    }
    while (l < r) {
        m = l + (r - l) / 2;
        if (s <= x * m)
            r = m;
        else
            l = m + 1;
    }
    cout << l;
    return 0;
}