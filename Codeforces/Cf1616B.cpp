#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s, ans = "";
    cin >> n;
    cin >> s;
    ans += s[0];
    for (int i = 1; i < n; ++i) {
        if (s[i] <= s[i-1] && s[i] < s[0])
            ans += s[i];
        else
            break;
    }
    cout << ans;
    for (int i = (int)(ans).size() - 1; i >= 0; --i)
        cout << ans[i];
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