// CF died during the contest...

#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

const int N = 300, INF = 1e9;
array<int, 2> dp[N][N][N];
// s, t, score

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s, t;
    cin >> s;
    cin >> t;
    int n = s.size(), m = t.size();
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                dp[i][j][k] = {INF, INF};
    dp[0][0][0] = {0, 0};
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            for (int _ = 0; _ < 2; ++_)
                for (int k = 0; k <= N - 10; ++k) {
                    if (i > 0) {
                        if (s[i - 1] == '(' && k > 0)
                            dp[i][j][k] = min(dp[i][j][k], {dp[i - 1][j][k - 1][0] + 1, 0});
                        if (s[i - 1] == ')')
                            dp[i][j][k] = min(dp[i][j][k], {dp[i - 1][j][k + 1][0] + 1, 1});
                    }
                    if (j > 0) {
                        if (t[j - 1] == '(' && k > 0)
                            dp[i][j][k] = min(dp[i][j][k], {dp[i][j - 1][k - 1][0] + 1, 2});
                        if (t[j - 1] == ')')
                            dp[i][j][k] = min(dp[i][j][k], {dp[i][j - 1][k + 1][0] + 1, 3});
                    }
                    if (i > 0 && j > 0 && s[i - 1] == t[j - 1]) {
                        if (s[i - 1] == '(' && k > 0)
                            dp[i][j][k] = min(dp[i][j][k], {dp[i - 1][j - 1][k - 1][0] + 1, 4});
                        if (s[i - 1] == ')')
                            dp[i][j][k] = min(dp[i][j][k], {dp[i - 1][j - 1][k + 1][0] + 1, 5});
                    }
                    dp[i][j][k] = min(dp[i][j][k], {dp[i][j][k + 1][0] + 1, 6});
                    if (k > 0)
                        dp[i][j][k] = min(dp[i][j][k], {dp[i][j][k - 1][0] + 1, 7});
                }
    int x = n, y = m, z = 0;
    // cout << dp[n][m][0][0] << endl;
    // return 0;
    string build = "";
    while (x > 0 || y > 0 || z > 0) {
        if (dp[x][y][z][1] == 0) {
            build += '(';
            --x;
            --z;
        }
        else if (dp[x][y][z][1] == 1) {
            build += ')';
            --x;
            ++z;
        }
        else if (dp[x][y][z][1] == 2) {
            build += '(';
            --y;
            --z;
        }
        else if (dp[x][y][z][1] == 3) {
            build += ')';
            --y;
            ++z;
        }
        else if (dp[x][y][z][1] == 4) {
            build += '(';
            --x;
            --y;
            --z;
        }
        else if (dp[x][y][z][1] == 5) {
            build += ')';
            --x;
            --y;
            ++z;
        }
        else if (dp[x][y][z][1] == 6) {
            build += ')';
            ++z;
        }
        else {
            build += '(';
            --z;
        }
    }
    while (!build.empty()) {
        cout << build.back();
        build.pop_back();
    }
    return 0;
}