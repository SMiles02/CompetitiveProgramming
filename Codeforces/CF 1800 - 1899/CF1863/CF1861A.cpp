#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    for (auto i : s) {
        for (auto j : s) {
            if ((i - '0') * (j - '0') == 21) {
                cout << i << j << "\n";
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}