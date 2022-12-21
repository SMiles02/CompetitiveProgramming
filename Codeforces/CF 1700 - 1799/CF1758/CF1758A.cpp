#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s;
    t = s;
    reverse(s.begin(), s.end());
    cout << s << t << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}