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

const int N = 101;
int dp[N][N][N][2]; // odd_left, even_left, sum, player (0 = A, 1 = B)

void solve() {
    int n, x = 0, y = 0, k;
    cin >> n;
    while (n--) {
        cin >> k;
        if (k & 1)
            ++x;
        else
            ++y;
    }
    // cout << x << " " << y << "\n";
    // cout << dp[2][0][1][1] << "\n";
    // cout << dp[1][0][0][0] << "\n";
    // cout << dp[0][0][1][1] << "\n";
    if (dp[x][y][0][0] == 1)
        cout << "Alice\n";
    else
        cout << "Bob\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    dp[0][0][0][0] = 1;
    dp[0][0][0][1] = 0;
    dp[0][0][1][0] = 0;
    dp[0][0][1][1] = 1;
    for (int sm = 1; sm < 101; ++sm)
        for (int o = 0; o <= sm; ++o) {
            int e = sm - o;
            for (int i = 0; i < 2; ++i) {
                // Alice
                if (o)
                    dp[o][e][i][0] = max(dp[o][e][i][0], 1 - dp[o - 1][e][1 - i][1]);
                if (e)
                    dp[o][e][i][0] = max(dp[o][e][i][0], 1 - dp[o][e - 1][i][1]);
                // Bob
                if (o)
                    dp[o][e][i][1] = max(dp[o][e][i][1], 1 - dp[o - 1][e][i][0]);
                if (e)
                    dp[o][e][i][1] = max(dp[o][e][i][1], 1 - dp[o][e - 1][i][0]);
                
            }
        }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}