#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s = 0, x;
    cin >> n;
    while (n--) {
        cin >> x;
        s += x - 1;
    }
    if (s & 1)
        cout << "errorgorn\n";
    else
        cout << "maomao90\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}