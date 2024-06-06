#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    string s;
    cin >> s;
    ll ans = 0;
    int cur = 0;
    for (auto i : s) {
        if (i == '1') {
            ++cur;
        }
        else if (cur) {
            ans += cur + 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}