#include <bits/stdc++.h>
using namespace std;

const int N = 3e5;
int n, a[N], x, y;

bool check(int k) {
    long long cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] >= k)
            cnt += (a[i] - k) / y;
        else
            cnt -= (k - a[i] + x - 1) / x;
    }
    return (cnt >= 0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int l = 1, r = 1e9, m;
    while (l < r) {
        m = l + (r - l) / 2 + 1;
        if (check(m))
            l = m;
        else
            r = m - 1;
    }
    cout << l;
    return 0;
}