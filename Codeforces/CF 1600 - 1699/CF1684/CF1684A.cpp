#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    char ans = '9';
    for (auto i : s)
        ans = min(ans, i);
    if (s.size() == 2)
        ans = s[1];
    cout << ans << "\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}