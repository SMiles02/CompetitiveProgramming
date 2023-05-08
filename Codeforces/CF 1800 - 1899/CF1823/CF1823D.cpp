#include <bits/stdc++.h>
using namespace std;

string alpha = "abcdefghijklmnopqrstuvwxyz";

void solve() {
    int n, k, last = 0;
    cin >> n >> k;
    int x[k + 1], c[k + 1];
    x[0] = c[0] = 3;
    for (int i = 1; i <= k; ++i)
        cin >> x[i];
    for (int i = 1; i <= k; ++i)
        cin >> c[i];
    for (int i = 1; i <= k; ++i) {
        if (x[i] - x[i - 1] < c[i] - c[i - 1] || x[i] < c[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    string s = "abc";
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < x[i] - x[i - 1] - c[i] + c[i - 1]; ++j)
            s += alpha[(last++) % 3];
        for (int j = 0; j < c[i] - c[i - 1]; ++j)
            s += alpha[i + 2];
    }
    cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}