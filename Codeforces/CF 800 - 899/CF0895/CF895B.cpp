#include <bits/stdc++.h>
using namespace std;

int d;

int div_count(int l, int r) {
    return (r / d) - (l / d) + (l % d == 0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, l, r, m, x, y;
    long long ans = 0;
    cin >> n >> d >> k;
    int b[n];
    vector<array<int, 2>> a = {{0, 0}};
    vector<int> p = {0};
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    sort(b, b + n);
    for (int i = 0; i < n; ++i) {
        if (b[i] != a.back()[0]) {
            a.push_back({b[i], 0});
            p.push_back(p.back());
        }
        ++a.back()[1];
        ++p.back();
    }
    n = a.size();
    for (int i = 1; i < n; ++i) {
        l = i;
        r = n - 1;
        while (l < r) {
            m = l + (r - l) / 2;
            if (div_count(a[i][0], a[m][0]) < k)
                l = m + 1;
            else
                r = m;
        }
        x = l;
        if (div_count(a[i][0], a[x][0]) != k)
            continue;
        l = i;
        r = n - 1;
        while (l < r) {
            m = l + (r - l) / 2 + 1;
            if (div_count(a[i][0], a[m][0]) > k)
                r = m - 1;
            else
                l = m;
        }
        y = l;
        ans += 1LL * a[i][1] * (p[y] - p[x - 1]);
    }
    cout << ans;
    return 0;
}