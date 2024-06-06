#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int get_score() {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            continue;
        }
        for (int j = i + 1; j < n; ++j) {
            sum += s[j] == '0';
        }
        for (int j = 0; j < i; ++j) {
            sum -= s[j] == '0';
        }
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    n = s.size();
    int ans = 0;
    get_score();
    const int C = 100 * 100;
    vector<int> dp(C * 2 + 5, 1e9);
    dp[get_score() + C] = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            for (int j = 0; j < i; ++j) {
                if (s[j] == '1') {
                    int cur = (i - j) * 2;
                    for (int k = 0; k + cur < dp.size(); ++k) {
                        dp[k] = min(dp[k], dp[k + cur] + 1);
                    }
                }
            }
        }
        if (s[i] == '0') {
            for (int j = i + 1; j < n; ++j) {
                if (s[j] == '1') {
                    int cur = (j - i) * 2;
                    for (int k = cur; k < dp.size(); ++k) {
                        dp[k] = min(dp[k], dp[k - cur] + 1);
                    }
                }
            }
        }
    }
    cout << dp[C];
    return 0;
}