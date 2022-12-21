#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, l = 0;
    cin >> n;
    while (n > 9) {
        ++l;
        n /= 10;
    }
    cout << l * 9 + n << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}