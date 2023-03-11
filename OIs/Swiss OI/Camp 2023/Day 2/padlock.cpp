#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, N = 1e5 + 1;
int dp[N][13];

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            for (int j = 0; j < 13; ++j)
                for (int k = 0; k < 10; ++k)
                    dp[i + 1][(j * 10 + k) % 13] = add(dp[i + 1][(j * 10 + k) % 13], dp[i][j]);
        }
        else {
            int k = s[i] - '0';
            for (int j = 0; j < 13; ++j)
                dp[i + 1][(j * 10 + k) % 13] = add(dp[i + 1][(j * 10 + k) % 13], dp[i][j]);
        }
    }
    cout << dp[n][7];
    return 0;
}