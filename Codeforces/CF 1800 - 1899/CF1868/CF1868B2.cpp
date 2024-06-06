#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, avg;
    cin >> n;
    long long sum = 0;
    vector<int> a(n), p(32), x(32), y(32);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n) {
        cout << "NO\n";
        return;
    }
    avg = sum / n;
    for (int i = 0; i < n; ++i) {
        if (a[i] == avg) {
            continue;
        }
        if (__builtin_popcount(abs(a[i] - avg)) == 1) {
            if (a[i] < avg) {
                ++p[__lg(avg - a[i]) + 1];
                --p[__lg(avg - a[i])];
                ++x[__lg(avg - a[i])];
            }
            else {
                --p[__lg(a[i] - avg) + 1];
                ++p[__lg(a[i] - avg)];
                ++y[__lg(a[i] - avg)];
            }
            continue;
        }
        bool done = false;
        for (int j = 0; j < 32; ++j) {
            for (int k = 0; k < 32; ++k) {
                if ((1LL << j) - (1LL << k) + a[i] == avg) {
                    done = true;
                    ++p[j];
                    --p[k];
                }
            }
        }
        if (!done) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < 32; ++i) {
        if (i + 1 < 32) {
            while (p[i] > 1 && y[i] > 0) {
                p[i] -= 2;
                ++p[i + 1];
                --y[i];
            }
            while (p[i] < -1 && x[i] > 0) {
                p[i] += 2;
                --p[i + 1];
                --x[i];
            }
        }
        if (p[i] != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}