#include <bits/stdc++.h>
using namespace std;

void solve() {
    for (int i = 0; i < 8; ++i) {
        string s;
        cin >> s;
        for (auto j : s) {
            if (j != '.') {
                cout << j;
            }
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}