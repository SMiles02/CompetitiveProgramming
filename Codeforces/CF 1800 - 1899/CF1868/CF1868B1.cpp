#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, avg;
    cin >> n;
    long long sum = 0;
    vector<int> a(n), p(32);
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