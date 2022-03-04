#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s;
    t = s;
    reverse(t.begin(), t.end());
    if (k == 0 || s == t)
        cout << "1\n";
    else
        cout << "2\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}