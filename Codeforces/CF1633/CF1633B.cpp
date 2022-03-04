#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (auto i : s) {
        if (i == '0')
            ++x;
        else
            ++y;
    }
    if (x == y)
        --x;
    cout << min(x, y) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}