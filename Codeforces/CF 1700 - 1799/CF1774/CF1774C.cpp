#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, cur = 1;
    cin >> n;
    string s;
    cin >> s;
    cout << "1 ";
    for (int i = 3; i <= n; ++i) {
        if (s[i - 2] == s[i - 3])
            ++cur;
        else
            cur = 1;
        cout << i - cur << " ";
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