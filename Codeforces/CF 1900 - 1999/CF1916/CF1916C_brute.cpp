#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

const int N = 35;
int dp[N + 1][N + 1][2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int s = 2; s < N; ++s) {
        for (int i = 0; i <= N; ++i) {
            int j = s - i;
            if (0 <= j && i + j <= N) {
                dp[i][j][0] = N * 2;
                dp[i][j][1] = 0;
                if (i > 1) {
                    dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1]);
                }
                if (j > 1) {
                    dp[i][j][0] = min(dp[i][j][0], dp[i + 1][j - 2][1]);
                }
                if (i > 0 && j > 0) {
                    dp[i][j][0] = min(dp[i][j][0], dp[i][j - 1][1] + 1);
                }
                if (i > 1) {
                    dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][0]);
                }
                if (j > 1) {
                    dp[i][j][1] = max(dp[i][j][1], dp[i + 1][j - 2][0]);
                }
                if (i > 0 && j > 0) {
                    dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][0] + 1);
                }
            }
        }
    }
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; i + j <= N; ++j) {
            cout << dp[i][j][0] << " ";
        }
        cout << "\n";
    }
    return 0;
}