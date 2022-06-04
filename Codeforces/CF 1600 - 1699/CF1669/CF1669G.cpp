#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, x = 0;
    cin >> n >> m;
    vector<string> s(n + 1, string(m, 'o'));
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int j = 0; j < m; ++j)
        for (int i = 0; i <= n; ++i) {
            if (s[i][j] == '*') {
                s[i][j] = '.';
                ++x;
            }
            else if (s[i][j] == 'o') {
                for (int k = 1; k <= x; ++k) 
                    s[i - k][j] = '*';
                x = 0;
            }
        }
    for (int i = 0; i < n; ++i)
        cout << s[i] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}