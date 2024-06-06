#include <bits/stdc++.h>
using namespace std;

bool check(int n) {

}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> dp(n + 1, -100);
    vector<bool> b(n + 1, true);
    for (int i = 1; i <= n; ++i) {
        b[i] = check(i, k);
    }
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = )
    }
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