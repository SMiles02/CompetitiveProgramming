#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x = 0;
    cin >> n;
    string s;
    cin >> s;
    for (auto i : s)
        x += (i == '1');
    if (x > 1 || n - x > 1)
        cout << "NO\n";
    else
        cout << "YES\n";
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}