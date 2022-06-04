#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (((b * 2 - c) % a == 0 && (b * 2 - c) / a > 0) || ((c - a) % 2 == 0 && (c - (c - a) / 2) % b == 0 && (c - (c - a) / 2) / b > 0) || ((b * 2 - a) % c == 0 && (b * 2 - a) / c > 0))
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