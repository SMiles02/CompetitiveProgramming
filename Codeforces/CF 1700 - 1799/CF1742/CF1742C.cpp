#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s[8];
    for (int i = 0; i < 8; ++i)
        cin >> s[i];
    for (int i = 0; i < 8; ++i) {
        bool all = true;
        for (int j = 0; j < 8; ++j)
            all = all & (s[i][j] == 'R');
        if (all) {
            cout << "R\n";
            return;
        }
    }
    cout << "B\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}