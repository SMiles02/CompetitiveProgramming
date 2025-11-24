#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.rbegin(), a.rend());
    vector<long long> dp(sum + 1);
    dp[0] = 1;
    for (int i : a) {
        for (int j = sum; j >= i; --j) {
            if (j - i <= sum / 2) {
                dp[j] += dp[j - i];
            }
        }
    }
    long long ans = 0;
    for (int i = sum / 2 + 1; i <= sum; ++i) {
        ans += dp[i];
    }
    cout << ans;
    return 0;
}