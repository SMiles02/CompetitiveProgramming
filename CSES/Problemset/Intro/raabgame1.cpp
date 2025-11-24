#include <bits/stdc++.h>
using namespace std;

// not correct

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a + b > n || a + b == 1 || max(a, b) == n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<int> x(n), y(n);
    for (int i = 0; i < n - a - b; ++i) {
        x[i] = y[i] = i + 1;
    }
    int al = n - a - b + 1, ar = n, bl = n - a - b + 1, br = n;
    for (int i = 0; i < a + b; ++i) {
        if (i < a) {
            x[n - a - b + i] = ar--;
            y[n - a - b + i] = bl++;
        }
        else {
            x[n - a - b + i] = al++;
            y[n - a - b + i] = br--;
        }
    }
    for (int i = 0; i < a + b; ++i) {
        if (x[n - a - b + i] == y[n - a - b + i]) {
            if (a > b) {
                swap(x[n - a - b + i], x[n - a - b + i + 1]);
            }
            else {
                swap(y[n - a - b + i], y[n - a - b + i - 1]);
            }
        }
    }
    for (int i : x) {
        cout << i << " ";
    }
    cout << "\n";
    for (int i : y) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}