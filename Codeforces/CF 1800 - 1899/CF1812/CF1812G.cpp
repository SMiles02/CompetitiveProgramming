#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s[2];
    cin >> s[0];
    cin >> s[1];
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < n; ++j)
            if (s[i][j] == 'G')
                s[i][j] = 'B';
    if (s[0] == s[1])
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}