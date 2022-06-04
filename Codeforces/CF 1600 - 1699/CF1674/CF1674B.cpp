#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    cout << 25 * (s[0] - 'a') + 1 + (s[1] - 'a') - (s[1] > s[0]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}