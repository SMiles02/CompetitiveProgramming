#include <bits/stdc++.h>
using namespace std;

bool rec(int i, int n, vector<int>& v) {
    if (i == n) {
        for (int j = 1; j <= n; ++j) {
            long long sum = 0;
            for (int k = j; k <= n; k += j) {
                sum += v[k - 1];
            }
            if (sum % j) {
                return false;
            }
        }
        for (int j : v) {
            cout << j << " ";
        }
        cout << "\n";
        return true;
    }
    for (int j = 1; j <= 1000; ++j) {
        v[i] = j;
        if (rec(i + 1, n, v)) {
            return true;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    rec(0, n, v);
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